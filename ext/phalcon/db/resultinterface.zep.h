
extern zend_class_entry *phalcon_db_resultinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_ResultInterface);

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_resultinterface_dataseek, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_resultinterface_dataseek, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_resultinterface_dataseek, 0, 0, 1)
#define arginfo_phalcon_db_resultinterface_dataseek NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, number, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, number)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_resultinterface_setfetchmode, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_resultinterface_setfetchmode, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, fetchMode, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, fetchMode)
#endif
	ZEND_ARG_INFO(0, colNoOrClassNameOrObject)
	ZEND_ARG_INFO(0, ctorargs)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_resultinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, execute, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, fetch, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, fetchArray, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, fetchAll, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, numRows, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, dataSeek, arginfo_phalcon_db_resultinterface_dataseek)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, setFetchMode, arginfo_phalcon_db_resultinterface_setfetchmode)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, getInternalResult, NULL)
	PHP_FE_END
};
