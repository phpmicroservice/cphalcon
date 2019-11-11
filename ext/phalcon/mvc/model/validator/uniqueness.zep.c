
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/object.h"


/**
 * Phalcon\Mvc\Model\Validator\Uniqueness
 *
 * Validates that a field or a combination of a set of fields are not
 * present more than once in the existing records of the related table
 *
 * This validator is only for use with Phalcon\Mvc\Collection. If you are using
 * Phalcon\Mvc\Model, please use the validators provided by Phalcon\Validation.
 *
 *<code>
 * use Phalcon\Mvc\Collection;
 * use Phalcon\Mvc\Model\Validator\Uniqueness;
 *
 * class Subscriptors extends Collection
 * {
 *     public function validation()
 *     {
 *         $this->validate(
 *             new Uniqueness(
 *                 [
 *                     "field"   => "email",
 *                     "message" => "Value of field 'email' is already present in another record",
 *                 ]
 *             )
 *         );
 *
 *         if ($this->validationHasFailed() === true) {
 *             return false;
 *         }
 *     }
 * }
 *</code>
 *
 * @deprecated 3.1.0
 * @see Phalcon\Validation\Validator\Uniqueness
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_Uniqueness) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Uniqueness, phalcon, mvc_model_validator_uniqueness, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_uniqueness_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validator
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Uniqueness, validate) {

	zend_class_entry *_47;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_11 = NULL, *_19 = NULL, *_37 = NULL, *_45 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, number = 0;
	zval *record, record_sub, field, dependencyInjector, metaData, message, bindTypes, bindDataTypes, columnMap, conditions, bindParams, composeField, columnField, bindType, primaryField, attributeField, params, className, replacePairs, _0, _26, _46, *_1$$5, _2$$5, _3$$8, _4$$8, _6$$10, _7$$10, _8$$6, _9$$6, _10$$6, _12$$13, _13$$13, _14$$15, _15$$15, _16$$11, _17$$11, _18$$11, _20$$18, _21$$18, _22$$20, _23$$20, _24$$16, _25$$16, _27$$21, *_28$$21, _29$$21, _30$$25, _31$$25, _32$$27, _33$$27, _34$$24, _35$$24, _36$$24, _38$$30, _39$$30, _40$$32, _41$$32, _42$$29, _43$$29, _44$$29, _48$$34, _52$$34, _49$$35, _50$$35, _51$$37;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&record_sub);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&composeField);
	ZVAL_UNDEF(&columnField);
	ZVAL_UNDEF(&bindType);
	ZVAL_UNDEF(&primaryField);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_20$$18);
	ZVAL_UNDEF(&_21$$18);
	ZVAL_UNDEF(&_22$$20);
	ZVAL_UNDEF(&_23$$20);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_27$$21);
	ZVAL_UNDEF(&_29$$21);
	ZVAL_UNDEF(&_30$$25);
	ZVAL_UNDEF(&_31$$25);
	ZVAL_UNDEF(&_32$$27);
	ZVAL_UNDEF(&_33$$27);
	ZVAL_UNDEF(&_34$$24);
	ZVAL_UNDEF(&_35$$24);
	ZVAL_UNDEF(&_36$$24);
	ZVAL_UNDEF(&_38$$30);
	ZVAL_UNDEF(&_39$$30);
	ZVAL_UNDEF(&_40$$32);
	ZVAL_UNDEF(&_41$$32);
	ZVAL_UNDEF(&_42$$29);
	ZVAL_UNDEF(&_43$$29);
	ZVAL_UNDEF(&_44$$29);
	ZVAL_UNDEF(&_48$$34);
	ZVAL_UNDEF(&_52$$34);
	ZVAL_UNDEF(&_49$$35);
	ZVAL_UNDEF(&_50$$35);
	ZVAL_UNDEF(&_51$$37);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	ZEPHIR_CALL_METHOD(&dependencyInjector, record, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "modelsMetadata");
	ZEPHIR_CALL_METHOD(&metaData, &dependencyInjector, "getshared", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&bindTypes);
	array_init(&bindTypes);
	ZEPHIR_CALL_METHOD(&bindDataTypes, &metaData, "getbindtypes", NULL, 0, record);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getreversecolumnmap", NULL, 0, record);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	ZEPHIR_INIT_VAR(&conditions);
	array_init(&conditions);
	ZEPHIR_INIT_VAR(&bindParams);
	array_init(&bindParams);
	number = 0;
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "field");
	ZEPHIR_CALL_METHOD(&field, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&field) == IS_ARRAY) {
		zephir_is_iterable(&field, 0, "phalcon/mvc/model/validator/uniqueness.zep", 130);
		if (Z_TYPE_P(&field) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&field), _1$$5)
			{
				ZEPHIR_INIT_NVAR(&composeField);
				ZVAL_COPY(&composeField, _1$$5);
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&columnField);
					if (!(zephir_array_isset_fetch(&columnField, &columnMap, &composeField, 0))) {
						ZEPHIR_INIT_NVAR(&_3$$8);
						object_init_ex(&_3$$8, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_4$$8);
						ZEPHIR_CONCAT_SVS(&_4$$8, "Column '", &composeField, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_3$$8, "__construct", &_5, 4, &_4$$8);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_3$$8, "phalcon/mvc/model/validator/uniqueness.zep", 107);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&columnField, &composeField);
				}
				ZEPHIR_OBS_NVAR(&bindType);
				if (!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &columnField, 0))) {
					ZEPHIR_INIT_NVAR(&_6$$10);
					object_init_ex(&_6$$10, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_NVAR(&_7$$10);
					ZEPHIR_CONCAT_SVS(&_7$$10, "Column '", &columnField, "' isn't part of the table columns");
					ZEPHIR_CALL_METHOD(NULL, &_6$$10, "__construct", &_5, 4, &_7$$10);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_6$$10, "phalcon/mvc/model/validator/uniqueness.zep", 117);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_8$$6);
				ZVAL_LONG(&_8$$6, number);
				ZEPHIR_INIT_NVAR(&_9$$6);
				ZEPHIR_CONCAT_SVSV(&_9$$6, "[", &composeField, "] = ?", &_8$$6);
				zephir_array_append(&conditions, &_9$$6, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 123);
				ZEPHIR_CALL_METHOD(&_10$$6, record, "readattribute", &_11, 0, &composeField);
				zephir_check_call_status();
				zephir_array_append(&bindParams, &_10$$6, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 124);
				zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 125);
				number++;
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &field, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$5, &field, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&composeField, &field, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&columnField);
						if (!(zephir_array_isset_fetch(&columnField, &columnMap, &composeField, 0))) {
							ZEPHIR_INIT_NVAR(&_12$$13);
							object_init_ex(&_12$$13, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_13$$13);
							ZEPHIR_CONCAT_SVS(&_13$$13, "Column '", &composeField, "' isn't part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_12$$13, "__construct", &_5, 4, &_13$$13);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_12$$13, "phalcon/mvc/model/validator/uniqueness.zep", 107);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CPY_WRT(&columnField, &composeField);
					}
					ZEPHIR_OBS_NVAR(&bindType);
					if (!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &columnField, 0))) {
						ZEPHIR_INIT_NVAR(&_14$$15);
						object_init_ex(&_14$$15, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_15$$15);
						ZEPHIR_CONCAT_SVS(&_15$$15, "Column '", &columnField, "' isn't part of the table columns");
						ZEPHIR_CALL_METHOD(NULL, &_14$$15, "__construct", &_5, 4, &_15$$15);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_14$$15, "phalcon/mvc/model/validator/uniqueness.zep", 117);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_16$$11);
					ZVAL_LONG(&_16$$11, number);
					ZEPHIR_INIT_NVAR(&_17$$11);
					ZEPHIR_CONCAT_SVSV(&_17$$11, "[", &composeField, "] = ?", &_16$$11);
					zephir_array_append(&conditions, &_17$$11, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 123);
					ZEPHIR_CALL_METHOD(&_18$$11, record, "readattribute", &_19, 0, &composeField);
					zephir_check_call_status();
					zephir_array_append(&bindParams, &_18$$11, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 124);
					zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 125);
					number++;
				ZEPHIR_CALL_METHOD(NULL, &field, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&composeField);
	} else {
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&columnField);
			if (!(zephir_array_isset_fetch(&columnField, &columnMap, &field, 0))) {
				ZEPHIR_INIT_VAR(&_20$$18);
				object_init_ex(&_20$$18, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(&_21$$18);
				ZEPHIR_CONCAT_SVS(&_21$$18, "Column '", &field, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, &_20$$18, "__construct", &_5, 4, &_21$$18);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_20$$18, "phalcon/mvc/model/validator/uniqueness.zep", 137);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&columnField, &field);
		}
		ZEPHIR_OBS_NVAR(&bindType);
		if (!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &columnField, 0))) {
			ZEPHIR_INIT_VAR(&_22$$20);
			object_init_ex(&_22$$20, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(&_23$$20);
			ZEPHIR_CONCAT_SVS(&_23$$20, "Column '", &columnField, "' isn't part of the table columns");
			ZEPHIR_CALL_METHOD(NULL, &_22$$20, "__construct", &_5, 4, &_23$$20);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_22$$20, "phalcon/mvc/model/validator/uniqueness.zep", 147);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_24$$16);
		ZEPHIR_CONCAT_SVS(&_24$$16, "[", &field, "] = ?0");
		zephir_array_append(&conditions, &_24$$16, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 153);
		ZEPHIR_CALL_METHOD(&_25$$16, record, "readattribute", NULL, 0, &field);
		zephir_check_call_status();
		zephir_array_append(&bindParams, &_25$$16, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 154);
		zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 155);
		number++;
	}
	ZEPHIR_CALL_METHOD(&_26, record, "getoperationmade", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_26, 2)) {
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, record);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&columnMap);
			ZVAL_NULL(&columnMap);
		}
		ZEPHIR_CALL_METHOD(&_27$$21, &metaData, "getprimarykeyattributes", NULL, 0, record);
		zephir_check_call_status();
		zephir_is_iterable(&_27$$21, 0, "phalcon/mvc/model/validator/uniqueness.zep", 200);
		if (Z_TYPE_P(&_27$$21) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_27$$21), _28$$21)
			{
				ZEPHIR_INIT_NVAR(&primaryField);
				ZVAL_COPY(&primaryField, _28$$21);
				ZEPHIR_OBS_NVAR(&bindType);
				if (!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &primaryField, 0))) {
					ZEPHIR_INIT_NVAR(&_30$$25);
					object_init_ex(&_30$$25, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_NVAR(&_31$$25);
					ZEPHIR_CONCAT_SVS(&_31$$25, "Column '", &primaryField, "' isn't part of the table columns");
					ZEPHIR_CALL_METHOD(NULL, &_30$$25, "__construct", &_5, 4, &_31$$25);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_30$$25, "phalcon/mvc/model/validator/uniqueness.zep", 177);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &primaryField, 0))) {
						ZEPHIR_INIT_NVAR(&_32$$27);
						object_init_ex(&_32$$27, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_33$$27);
						ZEPHIR_CONCAT_SVS(&_33$$27, "Column '", &primaryField, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_32$$27, "__construct", &_5, 4, &_33$$27);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_32$$27, "phalcon/mvc/model/validator/uniqueness.zep", 185);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &primaryField);
				}
				ZEPHIR_INIT_NVAR(&_34$$24);
				ZVAL_LONG(&_34$$24, number);
				ZEPHIR_INIT_NVAR(&_35$$24);
				ZEPHIR_CONCAT_SVSV(&_35$$24, "[", &attributeField, "] <> ?", &_34$$24);
				zephir_array_append(&conditions, &_35$$24, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 194);
				ZEPHIR_CALL_METHOD(&_36$$24, record, "readattribute", &_37, 0, &primaryField);
				zephir_check_call_status();
				zephir_array_append(&bindParams, &_36$$24, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 195);
				zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 196);
				number++;
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_27$$21, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_29$$21, &_27$$21, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_29$$21)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&primaryField, &_27$$21, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&bindType);
					if (!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &primaryField, 0))) {
						ZEPHIR_INIT_NVAR(&_38$$30);
						object_init_ex(&_38$$30, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_39$$30);
						ZEPHIR_CONCAT_SVS(&_39$$30, "Column '", &primaryField, "' isn't part of the table columns");
						ZEPHIR_CALL_METHOD(NULL, &_38$$30, "__construct", &_5, 4, &_39$$30);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_38$$30, "phalcon/mvc/model/validator/uniqueness.zep", 177);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &primaryField, 0))) {
							ZEPHIR_INIT_NVAR(&_40$$32);
							object_init_ex(&_40$$32, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_41$$32);
							ZEPHIR_CONCAT_SVS(&_41$$32, "Column '", &primaryField, "' isn't part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_40$$32, "__construct", &_5, 4, &_41$$32);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_40$$32, "phalcon/mvc/model/validator/uniqueness.zep", 185);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &primaryField);
					}
					ZEPHIR_INIT_NVAR(&_42$$29);
					ZVAL_LONG(&_42$$29, number);
					ZEPHIR_INIT_NVAR(&_43$$29);
					ZEPHIR_CONCAT_SVSV(&_43$$29, "[", &attributeField, "] <> ?", &_42$$29);
					zephir_array_append(&conditions, &_43$$29, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 194);
					ZEPHIR_CALL_METHOD(&_44$$29, record, "readattribute", &_45, 0, &primaryField);
					zephir_check_call_status();
					zephir_array_append(&bindParams, &_44$$29, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 195);
					zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 196);
					number++;
				ZEPHIR_CALL_METHOD(NULL, &_27$$21, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&primaryField);
	}
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	zephir_array_update_string(&params, SL("di"), &dependencyInjector, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_fast_join_str(&_0, SL(" AND "), &conditions);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&params, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&params, SL("bindTypes"), &bindTypes, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, record, 0);
	_47 = zephir_fetch_class(&className);
	ZEPHIR_CALL_CE_STATIC(&_46, _47, "count", NULL, 0, &params);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG(&_46, 0)) {
		ZEPHIR_INIT_VAR(&_48$$34);
		ZVAL_STRING(&_48$$34, "message");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_48$$34);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&replacePairs);
		if (Z_TYPE_P(&field) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_49$$35);
			zephir_create_array(&_49$$35, 1, 0);
			ZEPHIR_INIT_VAR(&_50$$35);
			zephir_fast_join_str(&_50$$35, SL(", "), &field);
			zephir_array_update_string(&_49$$35, SL(":fields"), &_50$$35, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&replacePairs, &_49$$35);
			if (ZEPHIR_IS_EMPTY(&message)) {
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_STRING(&message, "Value of fields: :fields are already present in another record");
			}
		} else {
			ZEPHIR_INIT_VAR(&_51$$37);
			zephir_create_array(&_51$$37, 1, 0);
			zephir_array_update_string(&_51$$37, SL(":field"), &field, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&replacePairs, &_51$$37);
			if (ZEPHIR_IS_EMPTY(&message)) {
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_STRING(&message, "Value of field: ':field' is already present in another record");
			}
		}
		ZEPHIR_CALL_FUNCTION(&_52$$34, "strtr", NULL, 22, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_48$$34);
		ZVAL_STRING(&_48$$34, "Unique");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, 0, &_52$$34, &field, &_48$$34);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

