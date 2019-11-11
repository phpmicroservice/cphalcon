
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 * Phalcon\Logger\Formatter
 *
 * This is a base class for logger formatters
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger, Formatter, phalcon, logger_formatter, phalcon_logger_formatter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(phalcon_logger_formatter_ce, 1, phalcon_logger_formatterinterface_ce);
	return SUCCESS;

}

/**
 * Returns the string meaning of a logger constant
 */
PHP_METHOD(Phalcon_Logger_Formatter, getTypeString) {

	zval *type_param = NULL;
	zend_long type;
	zval *this_ptr = getThis();


	zephir_fetch_params_without_memory_grow(1, 0, &type_param);

	type = zephir_get_intval(type_param);


	do {
		if (type == 7) {
			RETURN_STRING("DEBUG");
		}
		if (type == 3) {
			RETURN_STRING("ERROR");
		}
		if (type == 4) {
			RETURN_STRING("WARNING");
		}
		if (type == 1) {
			RETURN_STRING("CRITICAL");
		}
		if (type == 8) {
			RETURN_STRING("CUSTOM");
		}
		if (type == 2) {
			RETURN_STRING("ALERT");
		}
		if (type == 5) {
			RETURN_STRING("NOTICE");
		}
		if (type == 6) {
			RETURN_STRING("INFO");
		}
		if (type == 0) {
			RETURN_STRING("EMERGENCY");
		}
		if (type == 9) {
			RETURN_STRING("SPECIAL");
		}
	} while(0);

	RETURN_STRING("CUSTOM");

}

/**
 * Interpolates context values into the message placeholders
 *
 * @see http://www.php-fig.org/psr/psr-3/ Section 1.2 Message
 * @param string $message
 * @param array $context
 */
PHP_METHOD(Phalcon_Logger_Formatter, interpolate) {

	zend_string *_4$$3;
	zend_ulong _3$$3;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *context = NULL, context_sub, __$null, replace, key, value, *_1$$3, _2$$3, _5$$4, _6$$5;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&replace);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context);

	zephir_get_strval(&message, message_param);
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}


	_0 = Z_TYPE_P(context) == IS_ARRAY;
	if (_0) {
		_0 = zephir_fast_count_int(context) > 0;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&replace);
		array_init(&replace);
		zephir_is_iterable(context, 0, "phalcon/logger/formatter.zep", 89);
		if (Z_TYPE_P(context) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(context), _3$$3, _4$$3, _1$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_4$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _4$$3);
				} else {
					ZVAL_LONG(&key, _3$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _1$$3);
				ZEPHIR_INIT_NVAR(&_5$$4);
				ZEPHIR_CONCAT_SVS(&_5$$4, "{", &key, "}");
				zephir_array_update_zval(&replace, &_5$$4, &value, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, context, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$3, context, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, context, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, context, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_6$$5);
					ZEPHIR_CONCAT_SVS(&_6$$5, "{", &key, "}");
					zephir_array_update_zval(&replace, &_6$$5, &value, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, context, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 22, &message, &replace);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CTOR(&message);

}

