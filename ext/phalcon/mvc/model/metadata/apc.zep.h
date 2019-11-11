
extern zend_class_entry *phalcon_mvc_model_metadata_apc_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Apc);

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, __construct);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, read);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, write);
zend_object *zephir_init_properties_Phalcon_Mvc_Model_MetaData_Apc(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_apc___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_apc_read, 0, 1, IS_ARRAY, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_apc_read, 0, 1, IS_ARRAY, NULL, 1)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_apc_write, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_apc_write, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_apc_write, 0, 0, 2)
#define arginfo_phalcon_mvc_model_metadata_apc_write NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadata_apc_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Apc, __construct, arginfo_phalcon_mvc_model_metadata_apc___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Apc, read, arginfo_phalcon_mvc_model_metadata_apc_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Apc, write, arginfo_phalcon_mvc_model_metadata_apc_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
