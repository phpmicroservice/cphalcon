
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Phalcon\Db\Adapter\Pdo\Mysql
 *
 * Specific functions for the Mysql database system
 *
 *<code>
 * use Phalcon\Db\Adapter\Pdo\Mysql;
 *
 * $config = [
 *     "host"     => "localhost",
 *     "dbname"   => "blog",
 *     "port"     => 3306,
 *     "username" => "sigma",
 *     "password" => "secret",
 * ];
 *
 * $connection = new Mysql($config);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Mysql) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Mysql, phalcon, db_adapter_pdo_mysql, phalcon_db_adapter_pdo_ce, phalcon_db_adapter_pdo_mysql_method_entry, 0);

	zend_declare_property_string(phalcon_db_adapter_pdo_mysql_ce, SL("_type"), "mysql", ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalcon_db_adapter_pdo_mysql_ce, SL("_dialectType"), "mysql", ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Returns an array of Phalcon\Db\Column objects describing a table
 *
 * <code>
 * print_r(
 *     $connection->describeColumns("posts")
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeColumns) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_39 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, __$true, columns, columnType, field, definition, oldColumn, sizePattern, matches, matchOne, matchTwo, columnName, _0, _1, _2, _3, *_4, _5, _6$$4, _7$$5, _8$$5, _9$$6, _10$$6, _11$$7, _12$$8, _13$$9, _14$$10, _15$$11, _16$$12, _17$$13, _18$$13, _19$$14, _20$$14, _21$$15, _22$$15, _23$$16, _24$$16, _25$$17, _26$$18, _27$$19, _28$$20, _29$$21, _30$$22, _31$$24, _32$$25, _33$$3, _34$$3, _35$$3, _36$$3, _38$$3, _37$$32, _40$$33, _68$$33, _69$$33, _70$$33, _71$$33, _73$$33, _41$$34, _42$$35, _43$$35, _44$$36, _45$$36, _46$$37, _47$$38, _48$$39, _49$$40, _50$$41, _51$$42, _52$$43, _53$$43, _54$$44, _55$$44, _56$$45, _57$$45, _58$$46, _59$$46, _60$$47, _61$$48, _62$$49, _63$$50, _64$$51, _65$$52, _66$$54, _67$$55, _72$$62;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&oldColumn);
	ZVAL_UNDEF(&sizePattern);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&matchOne);
	ZVAL_UNDEF(&matchTwo);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_26$$18);
	ZVAL_UNDEF(&_27$$19);
	ZVAL_UNDEF(&_28$$20);
	ZVAL_UNDEF(&_29$$21);
	ZVAL_UNDEF(&_30$$22);
	ZVAL_UNDEF(&_31$$24);
	ZVAL_UNDEF(&_32$$25);
	ZVAL_UNDEF(&_33$$3);
	ZVAL_UNDEF(&_34$$3);
	ZVAL_UNDEF(&_35$$3);
	ZVAL_UNDEF(&_36$$3);
	ZVAL_UNDEF(&_38$$3);
	ZVAL_UNDEF(&_37$$32);
	ZVAL_UNDEF(&_40$$33);
	ZVAL_UNDEF(&_68$$33);
	ZVAL_UNDEF(&_69$$33);
	ZVAL_UNDEF(&_70$$33);
	ZVAL_UNDEF(&_71$$33);
	ZVAL_UNDEF(&_73$$33);
	ZVAL_UNDEF(&_41$$34);
	ZVAL_UNDEF(&_42$$35);
	ZVAL_UNDEF(&_43$$35);
	ZVAL_UNDEF(&_44$$36);
	ZVAL_UNDEF(&_45$$36);
	ZVAL_UNDEF(&_46$$37);
	ZVAL_UNDEF(&_47$$38);
	ZVAL_UNDEF(&_48$$39);
	ZVAL_UNDEF(&_49$$40);
	ZVAL_UNDEF(&_50$$41);
	ZVAL_UNDEF(&_51$$42);
	ZVAL_UNDEF(&_52$$43);
	ZVAL_UNDEF(&_53$$43);
	ZVAL_UNDEF(&_54$$44);
	ZVAL_UNDEF(&_55$$44);
	ZVAL_UNDEF(&_56$$45);
	ZVAL_UNDEF(&_57$$45);
	ZVAL_UNDEF(&_58$$46);
	ZVAL_UNDEF(&_59$$46);
	ZVAL_UNDEF(&_60$$47);
	ZVAL_UNDEF(&_61$$48);
	ZVAL_UNDEF(&_62$$49);
	ZVAL_UNDEF(&_63$$50);
	ZVAL_UNDEF(&_64$$51);
	ZVAL_UNDEF(&_65$$52);
	ZVAL_UNDEF(&_66$$54);
	ZVAL_UNDEF(&_67$$55);
	ZVAL_UNDEF(&_72$$62);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	ZEPHIR_INIT_VAR(&oldColumn);
	ZVAL_NULL(&oldColumn);
	ZEPHIR_INIT_VAR(&sizePattern);
	ZVAL_STRING(&sizePattern, "#\\(([0-9]+)(?:,\\s*([0-9]+))*\\)#");
	ZEPHIR_INIT_VAR(&columns);
	array_init(&columns);
	zephir_read_property(&_1, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describecolumns", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter/pdo/mysql.zep", 264);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _4);
			ZEPHIR_INIT_NVAR(&definition);
			zephir_create_array(&definition, 1, 0);
			add_assoc_long_ex(&definition, SL("bindType"), 2);
			ZEPHIR_OBS_NVAR(&columnType);
			zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 92);
			if (zephir_memnstr_str(&columnType, SL("enum"), "phalcon/db/adapter/pdo/mysql.zep", 94)) {
				ZEPHIR_INIT_NVAR(&_6$$4);
				ZVAL_LONG(&_6$$4, 5);
				zephir_array_update_string(&definition, SL("type"), &_6$$4, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/db/adapter/pdo/mysql.zep", 99)) {
				ZEPHIR_INIT_NVAR(&_7$$5);
				ZVAL_LONG(&_7$$5, 14);
				zephir_array_update_string(&definition, SL("type"), &_7$$5, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_8$$5);
				ZVAL_LONG(&_8$$5, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_8$$5, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("int"), "phalcon/db/adapter/pdo/mysql.zep", 106)) {
				ZEPHIR_INIT_NVAR(&_9$$6);
				ZVAL_LONG(&_9$$6, 0);
				zephir_array_update_string(&definition, SL("type"), &_9$$6, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_10$$6);
				ZVAL_LONG(&_10$$6, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_10$$6, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/db/adapter/pdo/mysql.zep", 113)) {
				ZEPHIR_INIT_NVAR(&_11$$7);
				ZVAL_LONG(&_11$$7, 2);
				zephir_array_update_string(&definition, SL("type"), &_11$$7, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/db/adapter/pdo/mysql.zep", 118)) {
				ZEPHIR_INIT_NVAR(&_12$$8);
				ZVAL_LONG(&_12$$8, 4);
				zephir_array_update_string(&definition, SL("type"), &_12$$8, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("char"), "phalcon/db/adapter/pdo/mysql.zep", 123)) {
				ZEPHIR_INIT_NVAR(&_13$$9);
				ZVAL_LONG(&_13$$9, 5);
				zephir_array_update_string(&definition, SL("type"), &_13$$9, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("date"), "phalcon/db/adapter/pdo/mysql.zep", 128)) {
				ZEPHIR_INIT_NVAR(&_14$$10);
				ZVAL_LONG(&_14$$10, 1);
				zephir_array_update_string(&definition, SL("type"), &_14$$10, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/db/adapter/pdo/mysql.zep", 133)) {
				ZEPHIR_INIT_NVAR(&_15$$11);
				ZVAL_LONG(&_15$$11, 17);
				zephir_array_update_string(&definition, SL("type"), &_15$$11, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("text"), "phalcon/db/adapter/pdo/mysql.zep", 138)) {
				ZEPHIR_INIT_NVAR(&_16$$12);
				ZVAL_LONG(&_16$$12, 6);
				zephir_array_update_string(&definition, SL("type"), &_16$$12, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/db/adapter/pdo/mysql.zep", 143)) {
				ZEPHIR_INIT_NVAR(&_17$$13);
				ZVAL_LONG(&_17$$13, 3);
				zephir_array_update_string(&definition, SL("type"), &_17$$13, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_18$$13);
				ZVAL_LONG(&_18$$13, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_18$$13, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("double"), "phalcon/db/adapter/pdo/mysql.zep", 150)) {
				ZEPHIR_INIT_NVAR(&_19$$14);
				ZVAL_LONG(&_19$$14, 9);
				zephir_array_update_string(&definition, SL("type"), &_19$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_20$$14);
				ZVAL_LONG(&_20$$14, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_20$$14, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("float"), "phalcon/db/adapter/pdo/mysql.zep", 157)) {
				ZEPHIR_INIT_NVAR(&_21$$15);
				ZVAL_LONG(&_21$$15, 7);
				zephir_array_update_string(&definition, SL("type"), &_21$$15, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_22$$15);
				ZVAL_LONG(&_22$$15, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_22$$15, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("bit"), "phalcon/db/adapter/pdo/mysql.zep", 164)) {
				ZEPHIR_INIT_NVAR(&_23$$16);
				ZVAL_LONG(&_23$$16, 8);
				zephir_array_update_string(&definition, SL("type"), &_23$$16, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_24$$16);
				ZVAL_LONG(&_24$$16, 5);
				zephir_array_update_string(&definition, SL("bindType"), &_24$$16, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("tinyblob"), "phalcon/db/adapter/pdo/mysql.zep", 170)) {
				ZEPHIR_INIT_NVAR(&_25$$17);
				ZVAL_LONG(&_25$$17, 10);
				zephir_array_update_string(&definition, SL("type"), &_25$$17, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("mediumblob"), "phalcon/db/adapter/pdo/mysql.zep", 175)) {
				ZEPHIR_INIT_NVAR(&_26$$18);
				ZVAL_LONG(&_26$$18, 12);
				zephir_array_update_string(&definition, SL("type"), &_26$$18, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("longblob"), "phalcon/db/adapter/pdo/mysql.zep", 180)) {
				ZEPHIR_INIT_NVAR(&_27$$19);
				ZVAL_LONG(&_27$$19, 13);
				zephir_array_update_string(&definition, SL("type"), &_27$$19, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("blob"), "phalcon/db/adapter/pdo/mysql.zep", 185)) {
				ZEPHIR_INIT_NVAR(&_28$$20);
				ZVAL_LONG(&_28$$20, 11);
				zephir_array_update_string(&definition, SL("type"), &_28$$20, PH_COPY | PH_SEPARATE);
			} else {
				ZEPHIR_INIT_NVAR(&_29$$21);
				ZVAL_LONG(&_29$$21, 2);
				zephir_array_update_string(&definition, SL("type"), &_29$$21, PH_COPY | PH_SEPARATE);
			}
			if (zephir_memnstr_str(&columnType, SL("("), "phalcon/db/adapter/pdo/mysql.zep", 200)) {
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_NULL(&matches);
				ZEPHIR_INIT_NVAR(&_30$$22);
				zephir_preg_match(&_30$$22, &sizePattern, &columnType, &matches, 0, 0 , 0 );
				if (zephir_is_true(&_30$$22)) {
					ZEPHIR_OBS_NVAR(&matchOne);
					if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0)) {
						ZEPHIR_INIT_NVAR(&_31$$24);
						ZVAL_LONG(&_31$$24, zephir_get_intval(&matchOne));
						zephir_array_update_string(&definition, SL("size"), &_31$$24, PH_COPY | PH_SEPARATE);
					}
					ZEPHIR_OBS_NVAR(&matchTwo);
					if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0)) {
						ZEPHIR_INIT_NVAR(&_32$$25);
						ZVAL_LONG(&_32$$25, zephir_get_intval(&matchTwo));
						zephir_array_update_string(&definition, SL("scale"), &_32$$25, PH_COPY | PH_SEPARATE);
					}
				}
			}
			if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/db/adapter/pdo/mysql.zep", 215)) {
				zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
			}
			if (Z_TYPE_P(&oldColumn) == IS_NULL) {
				zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_33$$3, &field, 3, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 231);
			if (ZEPHIR_IS_STRING(&_33$$3, "PRI")) {
				zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_34$$3, &field, 2, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 238);
			if (ZEPHIR_IS_STRING(&_34$$3, "NO")) {
				zephir_array_update_string(&definition, SL("notNull"), &__$true, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_35$$3, &field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 245);
			if (ZEPHIR_IS_STRING(&_35$$3, "auto_increment")) {
				zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
			}
			ZEPHIR_OBS_NVAR(&_36$$3);
			zephir_array_fetch_long(&_36$$3, &field, 4, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 252);
			if (Z_TYPE_P(&_36$$3) != IS_NULL) {
				zephir_array_fetch_long(&_37$$32, &field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 253);
				zephir_array_update_string(&definition, SL("default"), &_37$$32, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 259);
			ZEPHIR_INIT_NVAR(&_38$$3);
			object_init_ex(&_38$$3, phalcon_db_column_ce);
			ZEPHIR_CALL_METHOD(NULL, &_38$$3, "__construct", &_39, 154, &columnName, &definition);
			zephir_check_call_status();
			zephir_array_append(&columns, &_38$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 260);
			ZEPHIR_CPY_WRT(&oldColumn, &columnName);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_40$$33);
				zephir_create_array(&_40$$33, 1, 0);
				add_assoc_long_ex(&_40$$33, SL("bindType"), 2);
				ZEPHIR_CPY_WRT(&definition, &_40$$33);
				ZEPHIR_OBS_NVAR(&columnType);
				zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 92);
				if (zephir_memnstr_str(&columnType, SL("enum"), "phalcon/db/adapter/pdo/mysql.zep", 94)) {
					ZEPHIR_INIT_NVAR(&_41$$34);
					ZVAL_LONG(&_41$$34, 5);
					zephir_array_update_string(&definition, SL("type"), &_41$$34, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/db/adapter/pdo/mysql.zep", 99)) {
					ZEPHIR_INIT_NVAR(&_42$$35);
					ZVAL_LONG(&_42$$35, 14);
					zephir_array_update_string(&definition, SL("type"), &_42$$35, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_43$$35);
					ZVAL_LONG(&_43$$35, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_43$$35, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("int"), "phalcon/db/adapter/pdo/mysql.zep", 106)) {
					ZEPHIR_INIT_NVAR(&_44$$36);
					ZVAL_LONG(&_44$$36, 0);
					zephir_array_update_string(&definition, SL("type"), &_44$$36, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_45$$36);
					ZVAL_LONG(&_45$$36, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_45$$36, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/db/adapter/pdo/mysql.zep", 113)) {
					ZEPHIR_INIT_NVAR(&_46$$37);
					ZVAL_LONG(&_46$$37, 2);
					zephir_array_update_string(&definition, SL("type"), &_46$$37, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/db/adapter/pdo/mysql.zep", 118)) {
					ZEPHIR_INIT_NVAR(&_47$$38);
					ZVAL_LONG(&_47$$38, 4);
					zephir_array_update_string(&definition, SL("type"), &_47$$38, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("char"), "phalcon/db/adapter/pdo/mysql.zep", 123)) {
					ZEPHIR_INIT_NVAR(&_48$$39);
					ZVAL_LONG(&_48$$39, 5);
					zephir_array_update_string(&definition, SL("type"), &_48$$39, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("date"), "phalcon/db/adapter/pdo/mysql.zep", 128)) {
					ZEPHIR_INIT_NVAR(&_49$$40);
					ZVAL_LONG(&_49$$40, 1);
					zephir_array_update_string(&definition, SL("type"), &_49$$40, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/db/adapter/pdo/mysql.zep", 133)) {
					ZEPHIR_INIT_NVAR(&_50$$41);
					ZVAL_LONG(&_50$$41, 17);
					zephir_array_update_string(&definition, SL("type"), &_50$$41, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("text"), "phalcon/db/adapter/pdo/mysql.zep", 138)) {
					ZEPHIR_INIT_NVAR(&_51$$42);
					ZVAL_LONG(&_51$$42, 6);
					zephir_array_update_string(&definition, SL("type"), &_51$$42, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/db/adapter/pdo/mysql.zep", 143)) {
					ZEPHIR_INIT_NVAR(&_52$$43);
					ZVAL_LONG(&_52$$43, 3);
					zephir_array_update_string(&definition, SL("type"), &_52$$43, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_53$$43);
					ZVAL_LONG(&_53$$43, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_53$$43, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("double"), "phalcon/db/adapter/pdo/mysql.zep", 150)) {
					ZEPHIR_INIT_NVAR(&_54$$44);
					ZVAL_LONG(&_54$$44, 9);
					zephir_array_update_string(&definition, SL("type"), &_54$$44, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_55$$44);
					ZVAL_LONG(&_55$$44, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_55$$44, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("float"), "phalcon/db/adapter/pdo/mysql.zep", 157)) {
					ZEPHIR_INIT_NVAR(&_56$$45);
					ZVAL_LONG(&_56$$45, 7);
					zephir_array_update_string(&definition, SL("type"), &_56$$45, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_57$$45);
					ZVAL_LONG(&_57$$45, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_57$$45, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("bit"), "phalcon/db/adapter/pdo/mysql.zep", 164)) {
					ZEPHIR_INIT_NVAR(&_58$$46);
					ZVAL_LONG(&_58$$46, 8);
					zephir_array_update_string(&definition, SL("type"), &_58$$46, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_59$$46);
					ZVAL_LONG(&_59$$46, 5);
					zephir_array_update_string(&definition, SL("bindType"), &_59$$46, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("tinyblob"), "phalcon/db/adapter/pdo/mysql.zep", 170)) {
					ZEPHIR_INIT_NVAR(&_60$$47);
					ZVAL_LONG(&_60$$47, 10);
					zephir_array_update_string(&definition, SL("type"), &_60$$47, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("mediumblob"), "phalcon/db/adapter/pdo/mysql.zep", 175)) {
					ZEPHIR_INIT_NVAR(&_61$$48);
					ZVAL_LONG(&_61$$48, 12);
					zephir_array_update_string(&definition, SL("type"), &_61$$48, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("longblob"), "phalcon/db/adapter/pdo/mysql.zep", 180)) {
					ZEPHIR_INIT_NVAR(&_62$$49);
					ZVAL_LONG(&_62$$49, 13);
					zephir_array_update_string(&definition, SL("type"), &_62$$49, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("blob"), "phalcon/db/adapter/pdo/mysql.zep", 185)) {
					ZEPHIR_INIT_NVAR(&_63$$50);
					ZVAL_LONG(&_63$$50, 11);
					zephir_array_update_string(&definition, SL("type"), &_63$$50, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(&_64$$51);
					ZVAL_LONG(&_64$$51, 2);
					zephir_array_update_string(&definition, SL("type"), &_64$$51, PH_COPY | PH_SEPARATE);
				}
				if (zephir_memnstr_str(&columnType, SL("("), "phalcon/db/adapter/pdo/mysql.zep", 200)) {
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_NULL(&matches);
					ZEPHIR_INIT_NVAR(&_65$$52);
					zephir_preg_match(&_65$$52, &sizePattern, &columnType, &matches, 0, 0 , 0 );
					if (zephir_is_true(&_65$$52)) {
						ZEPHIR_OBS_NVAR(&matchOne);
						if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0)) {
							ZEPHIR_INIT_NVAR(&_66$$54);
							ZVAL_LONG(&_66$$54, zephir_get_intval(&matchOne));
							zephir_array_update_string(&definition, SL("size"), &_66$$54, PH_COPY | PH_SEPARATE);
						}
						ZEPHIR_OBS_NVAR(&matchTwo);
						if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0)) {
							ZEPHIR_INIT_NVAR(&_67$$55);
							ZVAL_LONG(&_67$$55, zephir_get_intval(&matchTwo));
							zephir_array_update_string(&definition, SL("scale"), &_67$$55, PH_COPY | PH_SEPARATE);
						}
					}
				}
				if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/db/adapter/pdo/mysql.zep", 215)) {
					zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
				}
				if (Z_TYPE_P(&oldColumn) == IS_NULL) {
					zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_68$$33, &field, 3, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 231);
				if (ZEPHIR_IS_STRING(&_68$$33, "PRI")) {
					zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_69$$33, &field, 2, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 238);
				if (ZEPHIR_IS_STRING(&_69$$33, "NO")) {
					zephir_array_update_string(&definition, SL("notNull"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_70$$33, &field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 245);
				if (ZEPHIR_IS_STRING(&_70$$33, "auto_increment")) {
					zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&_71$$33);
				zephir_array_fetch_long(&_71$$33, &field, 4, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 252);
				if (Z_TYPE_P(&_71$$33) != IS_NULL) {
					zephir_array_fetch_long(&_72$$62, &field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 253);
					zephir_array_update_string(&definition, SL("default"), &_72$$62, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&columnName);
				zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 259);
				ZEPHIR_INIT_NVAR(&_73$$33);
				object_init_ex(&_73$$33, phalcon_db_column_ce);
				ZEPHIR_CALL_METHOD(NULL, &_73$$33, "__construct", &_39, 154, &columnName, &definition);
				zephir_check_call_status();
				zephir_array_append(&columns, &_73$$33, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 260);
				ZEPHIR_CPY_WRT(&oldColumn, &columnName);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&field);
	RETURN_CCTOR(&columns);

}

/**
 * Lists table indexes
 *
 * <code>
 * print_r(
 *     $connection->describeIndexes("robots_parts")
 * );
 * </code>
 *
 * @param  string table
 * @param  string schema
 * @return \Phalcon\Db\IndexInterface[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeIndexes) {

	zend_string *_25;
	zend_ulong _24;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_29 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, __$null, indexes, index, keyName, indexType, indexObjects, columns, name, _0, _1, _2, _3, *_4, _5, *_22, _23, _6$$4, _7$$3, _9$$3, _10$$3, _8$$6, _11$$7, _12$$8, _13$$9, _14$$12, _15$$11, _17$$11, _18$$11, _16$$14, _19$$15, _20$$16, _21$$17, _26$$19, _27$$19, _28$$19, _30$$20, _31$$20, _32$$20;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&indexes);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&indexType);
	ZVAL_UNDEF(&indexObjects);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&_21$$17);
	ZVAL_UNDEF(&_26$$19);
	ZVAL_UNDEF(&_27$$19);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_31$$20);
	ZVAL_UNDEF(&_32$$20);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	ZEPHIR_INIT_VAR(&indexes);
	array_init(&indexes);
	zephir_read_property(&_1, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describeindexes", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 2);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter/pdo/mysql.zep", 313);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
		{
			ZEPHIR_INIT_NVAR(&index);
			ZVAL_COPY(&index, _4);
			zephir_array_fetch_string(&keyName, &index, SL("Key_name"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 286);
			zephir_array_fetch_string(&indexType, &index, SL("Index_type"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 287);
			if (!(zephir_array_isset(&indexes, &keyName))) {
				ZEPHIR_INIT_NVAR(&_6$$4);
				array_init(&_6$$4);
				zephir_array_update_zval(&indexes, &keyName, &_6$$4, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch(&_7$$3, &indexes, &keyName, PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 293);
			if (!(zephir_array_isset_string(&_7$$3, SL("columns")))) {
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
			} else {
				zephir_array_fetch(&_8$$6, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 296);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_8$$6, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 296);
			}
			zephir_array_fetch_string(&_9$$3, &index, SL("Column_name"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 299);
			zephir_array_append(&columns, &_9$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 299);
			zephir_array_update_multi(&indexes, &columns, SL("zs"), 3, &keyName, SL("columns"));
			zephir_array_fetch_string(&_10$$3, &index, SL("Non_unique"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 306);
			if (ZEPHIR_IS_STRING(&keyName, "PRIMARY")) {
				ZEPHIR_INIT_NVAR(&_11$$7);
				ZVAL_STRING(&_11$$7, "PRIMARY");
				zephir_array_update_multi(&indexes, &_11$$7, SL("zs"), 3, &keyName, SL("type"));
			} else if (ZEPHIR_IS_STRING(&indexType, "FULLTEXT")) {
				ZEPHIR_INIT_NVAR(&_12$$8);
				ZVAL_STRING(&_12$$8, "FULLTEXT");
				zephir_array_update_multi(&indexes, &_12$$8, SL("zs"), 3, &keyName, SL("type"));
			} else if (ZEPHIR_IS_LONG(&_10$$3, 0)) {
				ZEPHIR_INIT_NVAR(&_13$$9);
				ZVAL_STRING(&_13$$9, "UNIQUE");
				zephir_array_update_multi(&indexes, &_13$$9, SL("zs"), 3, &keyName, SL("type"));
			} else {
				zephir_array_update_multi(&indexes, &__$null, SL("zs"), 3, &keyName, SL("type"));
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&index, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&keyName);
				zephir_array_fetch_string(&keyName, &index, SL("Key_name"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 286);
				ZEPHIR_OBS_NVAR(&indexType);
				zephir_array_fetch_string(&indexType, &index, SL("Index_type"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 287);
				if (!(zephir_array_isset(&indexes, &keyName))) {
					ZEPHIR_INIT_NVAR(&_14$$12);
					array_init(&_14$$12);
					zephir_array_update_zval(&indexes, &keyName, &_14$$12, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch(&_15$$11, &indexes, &keyName, PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 293);
				if (!(zephir_array_isset_string(&_15$$11, SL("columns")))) {
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
				} else {
					zephir_array_fetch(&_16$$14, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 296);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_16$$14, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 296);
				}
				zephir_array_fetch_string(&_17$$11, &index, SL("Column_name"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 299);
				zephir_array_append(&columns, &_17$$11, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 299);
				zephir_array_update_multi(&indexes, &columns, SL("zs"), 3, &keyName, SL("columns"));
				zephir_array_fetch_string(&_18$$11, &index, SL("Non_unique"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 306);
				if (ZEPHIR_IS_STRING(&keyName, "PRIMARY")) {
					ZEPHIR_INIT_NVAR(&_19$$15);
					ZVAL_STRING(&_19$$15, "PRIMARY");
					zephir_array_update_multi(&indexes, &_19$$15, SL("zs"), 3, &keyName, SL("type"));
				} else if (ZEPHIR_IS_STRING(&indexType, "FULLTEXT")) {
					ZEPHIR_INIT_NVAR(&_20$$16);
					ZVAL_STRING(&_20$$16, "FULLTEXT");
					zephir_array_update_multi(&indexes, &_20$$16, SL("zs"), 3, &keyName, SL("type"));
				} else if (ZEPHIR_IS_LONG(&_18$$11, 0)) {
					ZEPHIR_INIT_NVAR(&_21$$17);
					ZVAL_STRING(&_21$$17, "UNIQUE");
					zephir_array_update_multi(&indexes, &_21$$17, SL("zs"), 3, &keyName, SL("type"));
				} else {
					zephir_array_update_multi(&indexes, &__$null, SL("zs"), 3, &keyName, SL("type"));
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_VAR(&indexObjects);
	array_init(&indexObjects);
	zephir_is_iterable(&indexes, 0, "phalcon/db/adapter/pdo/mysql.zep", 318);
	if (Z_TYPE_P(&indexes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&indexes), _24, _25, _22)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_25 != NULL) { 
				ZVAL_STR_COPY(&name, _25);
			} else {
				ZVAL_LONG(&name, _24);
			}
			ZEPHIR_INIT_NVAR(&index);
			ZVAL_COPY(&index, _22);
			ZEPHIR_INIT_NVAR(&_26$$19);
			object_init_ex(&_26$$19, phalcon_db_index_ce);
			zephir_array_fetch_string(&_27$$19, &index, SL("columns"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 315);
			zephir_array_fetch_string(&_28$$19, &index, SL("type"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 315);
			ZEPHIR_CALL_METHOD(NULL, &_26$$19, "__construct", &_29, 19, &name, &_27$$19, &_28$$19);
			zephir_check_call_status();
			zephir_array_update_zval(&indexObjects, &name, &_26$$19, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &indexes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_23, &indexes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_23)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &indexes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&index, &indexes, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_30$$20);
				object_init_ex(&_30$$20, phalcon_db_index_ce);
				zephir_array_fetch_string(&_31$$20, &index, SL("columns"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 315);
				zephir_array_fetch_string(&_32$$20, &index, SL("type"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 315);
				ZEPHIR_CALL_METHOD(NULL, &_30$$20, "__construct", &_29, 19, &name, &_31$$20, &_32$$20);
				zephir_check_call_status();
				zephir_array_update_zval(&indexObjects, &name, &_30$$20, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &indexes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&indexObjects);

}

/**
 * Lists table references
 *
 *<code>
 * print_r(
 *     $connection->describeReferences("robots_parts")
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeReferences) {

	zval _14$$3, _23$$6, _29$$9, _33$$10;
	zend_string *_27;
	zend_ulong _26;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_31 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, references, reference, arrayReference, constraintName, referenceObjects, name, referencedSchema, referencedTable, columns, referencedColumns, referenceUpdate, referenceDelete, _0, _1, _2, _3, *_4, _5, *_24, _25, _6$$5, _7$$5, _8$$5, _9$$5, _10$$5, _11$$5, _12$$3, _13$$3, _15$$8, _16$$8, _17$$8, _18$$8, _19$$8, _20$$8, _21$$6, _22$$6, _28$$9, _30$$9, _32$$10, _34$$10;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&references);
	ZVAL_UNDEF(&reference);
	ZVAL_UNDEF(&arrayReference);
	ZVAL_UNDEF(&constraintName);
	ZVAL_UNDEF(&referenceObjects);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&referencedSchema);
	ZVAL_UNDEF(&referencedTable);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&referencedColumns);
	ZVAL_UNDEF(&referenceUpdate);
	ZVAL_UNDEF(&referenceDelete);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_32$$10);
	ZVAL_UNDEF(&_34$$10);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_29$$9);
	ZVAL_UNDEF(&_33$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	ZEPHIR_INIT_VAR(&references);
	array_init(&references);
	zephir_read_property(&_1, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describereferences", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter/pdo/mysql.zep", 372);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
		{
			ZEPHIR_INIT_NVAR(&reference);
			ZVAL_COPY(&reference, _4);
			zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 341);
			if (!(zephir_array_isset(&references, &constraintName))) {
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 343);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 344);
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 345);
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 346);
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
				ZEPHIR_INIT_NVAR(&referencedColumns);
				array_init(&referencedColumns);
			} else {
				zephir_array_fetch(&_6$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 351);
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_string(&referencedSchema, &_6$$5, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 351);
				zephir_array_fetch(&_7$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 352);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_string(&referencedTable, &_7$$5, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 352);
				zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 353);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_8$$5, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 353);
				zephir_array_fetch(&_9$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 354);
				ZEPHIR_OBS_NVAR(&referencedColumns);
				zephir_array_fetch_string(&referencedColumns, &_9$$5, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 354);
				zephir_array_fetch(&_10$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 355);
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_string(&referenceUpdate, &_10$$5, SL("onUpdate"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 355);
				zephir_array_fetch(&_11$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 356);
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_string(&referenceDelete, &_11$$5, SL("onDelete"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 356);
			}
			zephir_array_fetch_long(&_12$$3, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 359);
			zephir_array_append(&columns, &_12$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 359);
			zephir_array_fetch_long(&_13$$3, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 360);
			zephir_array_append(&referencedColumns, &_13$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 360);
			ZEPHIR_INIT_NVAR(&_14$$3);
			zephir_create_array(&_14$$3, 6, 0);
			zephir_array_update_string(&_14$$3, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$3, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$3, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$3, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$3, SL("onUpdate"), &referenceUpdate, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$3, SL("onDelete"), &referenceDelete, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&references, &constraintName, &_14$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&reference, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&constraintName);
				zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 341);
				if (!(zephir_array_isset(&references, &constraintName))) {
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 343);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 344);
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 345);
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 346);
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
					ZEPHIR_INIT_NVAR(&referencedColumns);
					array_init(&referencedColumns);
				} else {
					zephir_array_fetch(&_15$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 351);
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_string(&referencedSchema, &_15$$8, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 351);
					zephir_array_fetch(&_16$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 352);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_string(&referencedTable, &_16$$8, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 352);
					zephir_array_fetch(&_17$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 353);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_17$$8, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 353);
					zephir_array_fetch(&_18$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 354);
					ZEPHIR_OBS_NVAR(&referencedColumns);
					zephir_array_fetch_string(&referencedColumns, &_18$$8, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 354);
					zephir_array_fetch(&_19$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 355);
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_string(&referenceUpdate, &_19$$8, SL("onUpdate"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 355);
					zephir_array_fetch(&_20$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 356);
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_string(&referenceDelete, &_20$$8, SL("onDelete"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 356);
				}
				zephir_array_fetch_long(&_21$$6, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 359);
				zephir_array_append(&columns, &_21$$6, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 359);
				zephir_array_fetch_long(&_22$$6, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 360);
				zephir_array_append(&referencedColumns, &_22$$6, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 360);
				ZEPHIR_INIT_NVAR(&_23$$6);
				zephir_create_array(&_23$$6, 6, 0);
				zephir_array_update_string(&_23$$6, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_23$$6, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_23$$6, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_23$$6, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_23$$6, SL("onUpdate"), &referenceUpdate, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_23$$6, SL("onDelete"), &referenceDelete, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&references, &constraintName, &_23$$6, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&reference);
	ZEPHIR_INIT_VAR(&referenceObjects);
	array_init(&referenceObjects);
	zephir_is_iterable(&references, 0, "phalcon/db/adapter/pdo/mysql.zep", 384);
	if (Z_TYPE_P(&references) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&references), _26, _27, _24)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_27 != NULL) { 
				ZVAL_STR_COPY(&name, _27);
			} else {
				ZVAL_LONG(&name, _26);
			}
			ZEPHIR_INIT_NVAR(&arrayReference);
			ZVAL_COPY(&arrayReference, _24);
			ZEPHIR_INIT_NVAR(&_28$$9);
			object_init_ex(&_28$$9, phalcon_db_reference_ce);
			ZEPHIR_INIT_NVAR(&_29$$9);
			zephir_create_array(&_29$$9, 6, 0);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 375);
			zephir_array_update_string(&_29$$9, SL("referencedSchema"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 376);
			zephir_array_update_string(&_29$$9, SL("referencedTable"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 377);
			zephir_array_update_string(&_29$$9, SL("columns"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 378);
			zephir_array_update_string(&_29$$9, SL("referencedColumns"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 379);
			zephir_array_update_string(&_29$$9, SL("onUpdate"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("onDelete"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 381);
			zephir_array_update_string(&_29$$9, SL("onDelete"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_28$$9, "__construct", &_31, 20, &name, &_29$$9);
			zephir_check_call_status();
			zephir_array_update_zval(&referenceObjects, &name, &_28$$9, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &references, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_25, &references, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_25)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &references, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&arrayReference, &references, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_32$$10);
				object_init_ex(&_32$$10, phalcon_db_reference_ce);
				ZEPHIR_INIT_NVAR(&_33$$10);
				zephir_create_array(&_33$$10, 6, 0);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 375);
				zephir_array_update_string(&_33$$10, SL("referencedSchema"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 376);
				zephir_array_update_string(&_33$$10, SL("referencedTable"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 377);
				zephir_array_update_string(&_33$$10, SL("columns"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 378);
				zephir_array_update_string(&_33$$10, SL("referencedColumns"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 379);
				zephir_array_update_string(&_33$$10, SL("onUpdate"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("onDelete"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 381);
				zephir_array_update_string(&_33$$10, SL("onDelete"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &_32$$10, "__construct", &_31, 20, &name, &_33$$10);
				zephir_check_call_status();
				zephir_array_update_zval(&referenceObjects, &name, &_32$$10, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &references, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&arrayReference);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&referenceObjects);

}

/**
 * Adds a foreign key to a table
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, addForeignKey) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *reference, reference_sub, foreignKeyCheck, _0, _1, _2, _3, _4;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&reference_sub);
	ZVAL_UNDEF(&foreignKeyCheck);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &reference);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getforeignkeychecks", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&foreignKeyCheck, this_ptr, "prepare", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &foreignKeyCheck, "execute", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_application_exception_ce, "DATABASE PARAMETER 'FOREIGN_KEY_CHECKS' HAS TO BE 1", "phalcon/db/adapter/pdo/mysql.zep", 396);
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_4, &_3, "addforeignkey", NULL, 0, &tableName, &schemaName, reference);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_4);
	zephir_check_call_status();
	RETURN_MM();

}

