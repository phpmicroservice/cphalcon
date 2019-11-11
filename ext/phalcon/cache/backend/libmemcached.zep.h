
extern zend_class_entry *phalcon_cache_backend_libmemcached_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Libmemcached);

PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, __construct);
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, _connect);
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, get);
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, save);
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, delete);
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, queryKeys);
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, exists);
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, increment);
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, decrement);
PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_libmemcached___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, frontend, Phalcon\\Cache\\FrontendInterface, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_libmemcached_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, keyName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, keyName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, lifetime, IS_LONG, 1)
#else
	ZEND_ARG_INFO(0, lifetime)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_libmemcached_save, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_libmemcached_save, 0, 0, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, stopBuffer, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, stopBuffer)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_libmemcached_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_libmemcached_querykeys, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_libmemcached_querykeys, 0, 0, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, prefix)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_libmemcached_exists, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_libmemcached_exists, 0, 0, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, keyName)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, lifetime, IS_LONG, 1)
#else
	ZEND_ARG_INFO(0, lifetime)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_libmemcached_increment, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_libmemcached_decrement, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_libmemcached_flush, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_libmemcached_flush, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_backend_libmemcached_method_entry) {
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, __construct, arginfo_phalcon_cache_backend_libmemcached___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, _connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, get, arginfo_phalcon_cache_backend_libmemcached_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, save, arginfo_phalcon_cache_backend_libmemcached_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, delete, arginfo_phalcon_cache_backend_libmemcached_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, queryKeys, arginfo_phalcon_cache_backend_libmemcached_querykeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, exists, arginfo_phalcon_cache_backend_libmemcached_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, increment, arginfo_phalcon_cache_backend_libmemcached_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, decrement, arginfo_phalcon_cache_backend_libmemcached_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, flush, arginfo_phalcon_cache_backend_libmemcached_flush, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
