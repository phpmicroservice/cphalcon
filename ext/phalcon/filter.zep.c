
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "Zend/zend_closures.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Phalcon\Filter
 *
 * The Phalcon\Filter component provides a set of commonly needed data filters. It provides
 * object oriented wrappers to the php filter extension. Also allows the developer to
 * define his/her own filters
 *
 *<code>
 * $filter = new \Phalcon\Filter();
 *
 * $filter->sanitize("some(one)@exa\\mple.com", "email"); // returns "someone@example.com"
 * $filter->sanitize("hello<<", "string"); // returns "hello"
 * $filter->sanitize("!100a019", "int"); // returns "100019"
 * $filter->sanitize("!100a019.01a", "float"); // returns "100019.01"
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Filter, phalcon, filter, phalcon_filter_method_entry, 0);

	zend_declare_property_null(phalcon_filter_ce, SL("_filters"), ZEND_ACC_PROTECTED);

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_EMAIL"), "email");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_ABSINT"), "absint");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_INT"), "int");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_INT_CAST"), "int!");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_STRING"), "string");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_FLOAT"), "float");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_FLOAT_CAST"), "float!");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_ALPHANUM"), "alphanum");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_TRIM"), "trim");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_STRIPTAGS"), "striptags");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_LOWER"), "lower");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_UPPER"), "upper");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_URL"), "url");

	zephir_declare_class_constant_string(phalcon_filter_ce, SL("FILTER_SPECIAL_CHARS"), "special_chars");

	zend_class_implements(phalcon_filter_ce, 1, phalcon_filterinterface_ce);
	return SUCCESS;

}

/**
 * Adds a user-defined filter
 */
PHP_METHOD(Phalcon_Filter, add) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *handler, handler_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&handler_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	_0 = Z_TYPE_P(handler) != IS_OBJECT;
	if (_0) {
		_0 = !(zephir_is_callable(handler));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_filter_exception_ce, "Filter must be an object or callable", "phalcon/filter.zep", 79);
		return;
	}
	zephir_update_property_array(this_ptr, SL("_filters"), &name, handler);
	RETURN_THIS();

}

/**
 * Sanitizes a value with a specified single or set of filters
 */
PHP_METHOD(Phalcon_Filter, sanitize) {

	zend_string *_6$$6, *_15$$11, *_23$$15;
	zend_ulong _5$$6, _14$$11, _22$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool noRecursive, _19, _2$$5, _11$$10;
	zval *value = NULL, value_sub, *filters, filters_sub, *noRecursive_param = NULL, filter, arrayValue, itemKey, itemValue, sanitizedValue, *_0$$4, _1$$4, *_3$$6, _4$$6, _7$$7, _9$$8, _10$$9, *_12$$11, _13$$11, _16$$12, _17$$13, _18$$14, *_20$$15, _21$$15, _24$$16, _25$$17;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&arrayValue);
	ZVAL_UNDEF(&itemKey);
	ZVAL_UNDEF(&itemValue);
	ZVAL_UNDEF(&sanitizedValue);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_25$$17);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &value, &filters, &noRecursive_param);

	ZEPHIR_SEPARATE_PARAM(value);
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	if (Z_TYPE_P(filters) == IS_ARRAY) {
		if (Z_TYPE_P(value) != IS_NULL) {
			zephir_is_iterable(filters, 0, "phalcon/filter.zep", 112);
			if (Z_TYPE_P(filters) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(filters), _0$$4)
				{
					ZEPHIR_INIT_NVAR(&filter);
					ZVAL_COPY(&filter, _0$$4);
					_2$$5 = Z_TYPE_P(value) == IS_ARRAY;
					if (_2$$5) {
						_2$$5 = !noRecursive;
					}
					if (_2$$5) {
						ZEPHIR_INIT_NVAR(&arrayValue);
						array_init(&arrayValue);
						zephir_is_iterable(value, 0, "phalcon/filter.zep", 107);
						if (Z_TYPE_P(value) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(value), _5$$6, _6$$6, _3$$6)
							{
								ZEPHIR_INIT_NVAR(&itemKey);
								if (_6$$6 != NULL) { 
									ZVAL_STR_COPY(&itemKey, _6$$6);
								} else {
									ZVAL_LONG(&itemKey, _5$$6);
								}
								ZEPHIR_INIT_NVAR(&itemValue);
								ZVAL_COPY(&itemValue, _3$$6);
								ZEPHIR_CALL_METHOD(&_7$$7, this_ptr, "_sanitize", &_8, 0, &itemValue, &filter);
								zephir_check_call_status();
								zephir_array_update_zval(&arrayValue, &itemKey, &_7$$7, PH_COPY | PH_SEPARATE);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, value, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_4$$6, value, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_4$$6)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&itemKey, value, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&itemValue, value, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&_9$$8, this_ptr, "_sanitize", &_8, 0, &itemValue, &filter);
									zephir_check_call_status();
									zephir_array_update_zval(&arrayValue, &itemKey, &_9$$8, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(NULL, value, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&itemValue);
						ZEPHIR_INIT_NVAR(&itemKey);
						ZEPHIR_CPY_WRT(value, &arrayValue);
					} else {
						ZEPHIR_CALL_METHOD(&_10$$9, this_ptr, "_sanitize", &_8, 0, value, &filter);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(value, &_10$$9);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, filters, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_1$$4, filters, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_1$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&filter, filters, "current", NULL, 0);
					zephir_check_call_status();
						_11$$10 = Z_TYPE_P(value) == IS_ARRAY;
						if (_11$$10) {
							_11$$10 = !noRecursive;
						}
						if (_11$$10) {
							ZEPHIR_INIT_NVAR(&arrayValue);
							array_init(&arrayValue);
							zephir_is_iterable(value, 0, "phalcon/filter.zep", 107);
							if (Z_TYPE_P(value) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(value), _14$$11, _15$$11, _12$$11)
								{
									ZEPHIR_INIT_NVAR(&itemKey);
									if (_15$$11 != NULL) { 
										ZVAL_STR_COPY(&itemKey, _15$$11);
									} else {
										ZVAL_LONG(&itemKey, _14$$11);
									}
									ZEPHIR_INIT_NVAR(&itemValue);
									ZVAL_COPY(&itemValue, _12$$11);
									ZEPHIR_CALL_METHOD(&_16$$12, this_ptr, "_sanitize", &_8, 0, &itemValue, &filter);
									zephir_check_call_status();
									zephir_array_update_zval(&arrayValue, &itemKey, &_16$$12, PH_COPY | PH_SEPARATE);
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, value, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_13$$11, value, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_13$$11)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&itemKey, value, "key", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&itemValue, value, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_CALL_METHOD(&_17$$13, this_ptr, "_sanitize", &_8, 0, &itemValue, &filter);
										zephir_check_call_status();
										zephir_array_update_zval(&arrayValue, &itemKey, &_17$$13, PH_COPY | PH_SEPARATE);
									ZEPHIR_CALL_METHOD(NULL, value, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&itemValue);
							ZEPHIR_INIT_NVAR(&itemKey);
							ZEPHIR_CPY_WRT(value, &arrayValue);
						} else {
							ZEPHIR_CALL_METHOD(&_18$$14, this_ptr, "_sanitize", &_8, 0, value, &filter);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(value, &_18$$14);
						}
					ZEPHIR_CALL_METHOD(NULL, filters, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&filter);
		}
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	_19 = Z_TYPE_P(value) == IS_ARRAY;
	if (_19) {
		_19 = !noRecursive;
	}
	if (_19) {
		ZEPHIR_INIT_VAR(&sanitizedValue);
		array_init(&sanitizedValue);
		zephir_is_iterable(value, 0, "phalcon/filter.zep", 124);
		if (Z_TYPE_P(value) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(value), _22$$15, _23$$15, _20$$15)
			{
				ZEPHIR_INIT_NVAR(&itemKey);
				if (_23$$15 != NULL) { 
					ZVAL_STR_COPY(&itemKey, _23$$15);
				} else {
					ZVAL_LONG(&itemKey, _22$$15);
				}
				ZEPHIR_INIT_NVAR(&itemValue);
				ZVAL_COPY(&itemValue, _20$$15);
				ZEPHIR_CALL_METHOD(&_24$$16, this_ptr, "_sanitize", &_8, 0, &itemValue, filters);
				zephir_check_call_status();
				zephir_array_update_zval(&sanitizedValue, &itemKey, &_24$$16, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, value, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_21$$15, value, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_21$$15)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&itemKey, value, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&itemValue, value, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_25$$17, this_ptr, "_sanitize", &_8, 0, &itemValue, filters);
					zephir_check_call_status();
					zephir_array_update_zval(&sanitizedValue, &itemKey, &_25$$17, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, value, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&itemValue);
		ZEPHIR_INIT_NVAR(&itemKey);
		RETURN_CCTOR(&sanitizedValue);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_sanitize", &_8, 0, value, filters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Internal sanitize wrapper to filter_var
 */
PHP_METHOD(Phalcon_Filter, _sanitize) {

	zval _3$$4, _9$$10;
	zend_bool _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filter, _16$$21;
	zval *value, value_sub, *filter_param = NULL, filterObject, _0, _4$$5, _5$$5, _6$$6, _7$$8, _8$$9, _10$$10, _11$$12, _12$$12, _13$$19, _14$$20, _15$$21;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&filterObject);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$19);
	ZVAL_UNDEF(&_14$$20);
	ZVAL_UNDEF(&_15$$21);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&_16$$21);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_9$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value, &filter_param);

	if (UNEXPECTED(Z_TYPE_P(filter_param) != IS_STRING && Z_TYPE_P(filter_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filter' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(filter_param) == IS_STRING)) {
		zephir_get_strval(&filter, filter_param);
	} else {
		ZEPHIR_INIT_VAR(&filter);
		ZVAL_EMPTY_STRING(&filter);
	}


	ZEPHIR_OBS_VAR(&filterObject);
	zephir_read_property(&_0, this_ptr, SL("_filters"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&filterObject, &_0, &filter, 0)) {
		_1$$3 = Z_TYPE_P(&filterObject) == IS_OBJECT;
		if (_1$$3) {
			_1$$3 = zephir_instance_of_ev(&filterObject, zend_ce_closure);
		}
		_2$$3 = _1$$3;
		if (!(_2$$3)) {
			_2$$3 = zephir_is_callable(&filterObject);
		}
		if (_2$$3) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 1, 0);
			zephir_array_fast_append(&_3$$4, value);
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &filterObject, &_3$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_RETURN_CALL_METHOD(&filterObject, "filter", NULL, 0, value);
		zephir_check_call_status();
		RETURN_MM();
	}
	do {
		if (ZEPHIR_IS_STRING(&filter, "email")) {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "FILTER_SANITIZE_EMAIL");
			ZEPHIR_CALL_FUNCTION(&_5$$5, "constant", NULL, 32, &_4$$5);
			zephir_check_call_status();
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 194, value, &_5$$5);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "int")) {
			ZVAL_LONG(&_6$$6, 519);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 194, value, &_6$$6);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "int!")) {
			RETURN_MM_LONG(zephir_get_intval(value));
		}
		if (ZEPHIR_IS_STRING(&filter, "absint")) {
			ZVAL_LONG(&_7$$8, zephir_get_intval(value));
			ZEPHIR_RETURN_CALL_FUNCTION("abs", NULL, 195, &_7$$8);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "string")) {
			ZVAL_LONG(&_8$$9, 513);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 194, value, &_8$$9);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "float")) {
			ZEPHIR_INIT_VAR(&_9$$10);
			zephir_create_array(&_9$$10, 1, 0);
			add_assoc_long_ex(&_9$$10, SL("flags"), 4096);
			ZVAL_LONG(&_10$$10, 520);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 194, value, &_10$$10, &_9$$10);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "float!")) {
			RETURN_MM_DOUBLE(zephir_get_doubleval(value));
		}
		if (ZEPHIR_IS_STRING(&filter, "alphanum")) {
			ZEPHIR_INIT_VAR(&_11$$12);
			ZVAL_STRING(&_11$$12, "/[^A-Za-z0-9]/");
			ZEPHIR_INIT_VAR(&_12$$12);
			ZVAL_STRING(&_12$$12, "");
			ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 35, &_11$$12, &_12$$12, value);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "trim")) {
			zephir_fast_trim(return_value, value, NULL , ZEPHIR_TRIM_BOTH);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "striptags")) {
			ZEPHIR_RETURN_CALL_FUNCTION("strip_tags", NULL, 196, value);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "lower")) {
			if ((zephir_function_exists_ex(ZEND_STRL("mb_strtolower")) == SUCCESS)) {
				ZEPHIR_RETURN_CALL_FUNCTION("mb_strtolower", NULL, 197, value);
				zephir_check_call_status();
				RETURN_MM();
			}
			zephir_fast_strtolower(return_value, value);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "upper")) {
			if ((zephir_function_exists_ex(ZEND_STRL("mb_strtoupper")) == SUCCESS)) {
				ZEPHIR_RETURN_CALL_FUNCTION("mb_strtoupper", NULL, 198, value);
				zephir_check_call_status();
				RETURN_MM();
			}
			zephir_fast_strtoupper(return_value, value);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "url")) {
			ZVAL_LONG(&_13$$19, 518);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 194, value, &_13$$19);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "special_chars")) {
			ZVAL_LONG(&_14$$20, 515);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 194, value, &_14$$20);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_15$$21);
		object_init_ex(&_15$$21, phalcon_filter_exception_ce);
		ZEPHIR_INIT_VAR(&_16$$21);
		ZEPHIR_CONCAT_SVS(&_16$$21, "Sanitize filter '", &filter, "' is not supported");
		ZEPHIR_CALL_METHOD(NULL, &_15$$21, "__construct", NULL, 4, &_16$$21);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_15$$21, "phalcon/filter.zep", 226);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * Return the user-defined filters in the instance
 */
PHP_METHOD(Phalcon_Filter, getFilters) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_filters");

}

