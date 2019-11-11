
extern zend_class_entry *phalcon_cache_multiple_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Multiple);

PHP_METHOD(Phalcon_Cache_Multiple, __construct);
PHP_METHOD(Phalcon_Cache_Multiple, push);
PHP_METHOD(Phalcon_Cache_Multiple, get);
PHP_METHOD(Phalcon_Cache_Multiple, start);
PHP_METHOD(Phalcon_Cache_Multiple, save);
PHP_METHOD(Phalcon_Cache_Multiple, delete);
PHP_METHOD(Phalcon_Cache_Multiple, exists);
PHP_METHOD(Phalcon_Cache_Multiple, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_multiple___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, backends)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cache_multiple_push, 0, 1, Phalcon\\Cache\\Multiple, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_multiple_push, 0, 1, IS_OBJECT, "Phalcon\\Cache\\Multiple", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, backend, Phalcon\\Cache\\BackendInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_multiple_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_multiple_start, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_multiple_start, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_multiple_start, 0, 0, 1)
#define arginfo_phalcon_cache_multiple_start NULL
#endif

	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_multiple_save, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_multiple_save, 0, 0, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_multiple_save, 0, 0, 0)
#define arginfo_phalcon_cache_multiple_save NULL
#endif

	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_multiple_delete, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_multiple_delete, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_multiple_exists, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_multiple_exists, 0, 0, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_multiple_flush, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_multiple_flush, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_multiple_method_entry) {
	PHP_ME(Phalcon_Cache_Multiple, __construct, arginfo_phalcon_cache_multiple___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Multiple, push, arginfo_phalcon_cache_multiple_push, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Multiple, get, arginfo_phalcon_cache_multiple_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Multiple, start, arginfo_phalcon_cache_multiple_start, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Multiple, save, arginfo_phalcon_cache_multiple_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Multiple, delete, arginfo_phalcon_cache_multiple_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Multiple, exists, arginfo_phalcon_cache_multiple_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Multiple, flush, arginfo_phalcon_cache_multiple_flush, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
