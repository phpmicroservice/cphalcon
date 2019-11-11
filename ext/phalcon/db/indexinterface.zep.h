
extern zend_class_entry *phalcon_db_indexinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_IndexInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_indexinterface___set_state, 0, 1, Phalcon\\Db\\IndexInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_indexinterface___set_state, 0, 1, IS_OBJECT, "Phalcon\\Db\\IndexInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_indexinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, getColumns, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, getType, NULL)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_db_indexinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
