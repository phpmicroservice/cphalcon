
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/file.h"


/**
 * Phalcon\Http\Request
 *
 * Encapsulates request information for easy and secure access from application controllers.
 *
 * The request object is a simple value object that is passed between the dispatcher and controller classes.
 * It packages the HTTP request environment.
 *
 *<code>
 * use Phalcon\Http\Request;
 *
 * $request = new Request();
 *
 * if ($request->isPost() && $request->isAjax()) {
 *     echo "Request was made using POST and AJAX";
 * }
 *
 * $request->getServer("HTTP_HOST"); // Retrieve SERVER variables
 * $request->getMethod();            // GET, POST, PUT, DELETE, HEAD, OPTIONS, PATCH, PURGE, TRACE, CONNECT
 * $request->getLanguages();         // An array of languages the client accepts
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Request) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http, Request, phalcon, http_request, phalcon_http_request_method_entry, 0);

	zend_declare_property_null(phalcon_http_request_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_http_request_ce, SL("_rawBody"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_http_request_ce, SL("_filter"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_http_request_ce, SL("_putCache"), ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalcon_http_request_ce, SL("_httpMethodParameterOverride"), 0, ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalcon_http_request_ce, SL("_strictHostCheck"), 0, ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_http_request_ce, 1, phalcon_http_requestinterface_ce);
	zend_class_implements(phalcon_http_request_ce, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Http_Request, getHttpMethodParameterOverride) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_httpMethodParameterOverride");

}

PHP_METHOD(Phalcon_Http_Request, setHttpMethodParameterOverride) {

	zval *httpMethodParameterOverride, httpMethodParameterOverride_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpMethodParameterOverride_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &httpMethodParameterOverride);



	zephir_update_property_zval(this_ptr, SL("_httpMethodParameterOverride"), httpMethodParameterOverride);
	RETURN_THISW();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Http_Request, setDI) {

	zval *dependencyInjector, dependencyInjector_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &dependencyInjector);



	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Http_Request, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Gets a variable from the $_REQUEST superglobal applying filters if needed.
 * If no parameters are given the $_REQUEST superglobal is returned
 *
 *<code>
 * // Returns value from $_REQUEST["user_email"] without sanitizing
 * $userEmail = $request->get("user_email");
 *
 * // Returns value from $_REQUEST["user_email"] with sanitizing
 * $userEmail = $request->get("user_email", "email");
 *</code>
 */
PHP_METHOD(Phalcon_Http_Request, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, _REQUEST, __$null, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_REQUEST);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
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
	}
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		notAllowEmpty = zephir_get_boolval(notAllowEmpty_param);
	}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	if (notAllowEmpty) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	if (noRecursive) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 207, &_REQUEST, &name, filters, defaultValue, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets a variable from the $_POST superglobal applying filters if needed
 * If no parameters are given the $_POST superglobal is returned
 *
 *<code>
 * // Returns value from $_POST["user_email"] without sanitizing
 * $userEmail = $request->getPost("user_email");
 *
 * // Returns value from $_POST["user_email"] with sanitizing
 * $userEmail = $request->getPost("user_email", "email");
 *</code>
 */
PHP_METHOD(Phalcon_Http_Request, getPost) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, _POST, __$null, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_POST);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SL("_POST"));
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
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
	}
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		notAllowEmpty = zephir_get_boolval(notAllowEmpty_param);
	}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	if (notAllowEmpty) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	if (noRecursive) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 207, &_POST, &name, filters, defaultValue, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets a variable from put request
 *
 *<code>
 * // Returns value from $_PUT["user_email"] without sanitizing
 * $userEmail = $request->getPut("user_email");
 *
 * // Returns value from $_PUT["user_email"] with sanitizing
 * $userEmail = $request->getPut("user_email", "email");
 *</code>
 */
PHP_METHOD(Phalcon_Http_Request, getPut) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive, _0$$3;
	zval *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, __$null, put, contentType, _5, _6, _1$$3, _2$$3, _3$$4, _4$$6;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&put);
	ZVAL_UNDEF(&contentType);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
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
	}
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		notAllowEmpty = zephir_get_boolval(notAllowEmpty_param);
	}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	ZEPHIR_OBS_VAR(&put);
	zephir_read_property(&put, this_ptr, SL("_putCache"), PH_NOISY_CC);
	if (Z_TYPE_P(&put) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&contentType, this_ptr, "getcontenttype", NULL, 0);
		zephir_check_call_status();
		_0$$3 = Z_TYPE_P(&contentType) == IS_STRING;
		if (_0$$3) {
			ZEPHIR_INIT_VAR(&_1$$3);
			ZVAL_STRING(&_1$$3, "json");
			ZEPHIR_CALL_FUNCTION(&_2$$3, "stripos", NULL, 208, &contentType, &_1$$3);
			zephir_check_call_status();
			_0$$3 = !ZEPHIR_IS_FALSE(&_2$$3);
		}
		if (_0$$3) {
			ZVAL_BOOL(&_3$$4, 1);
			ZEPHIR_CALL_METHOD(&put, this_ptr, "getjsonrawbody", NULL, 0, &_3$$4);
			zephir_check_call_status();
			if (Z_TYPE_P(&put) != IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&put);
				array_init(&put);
			}
		} else {
			ZEPHIR_INIT_NVAR(&put);
			array_init(&put);
			ZEPHIR_CALL_METHOD(&_4$$6, this_ptr, "getrawbody", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_MAKE_REF(&put);
			ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 209, &_4$$6, &put);
			ZEPHIR_UNREF(&put);
			zephir_check_call_status();
		}
		zephir_update_property_zval(this_ptr, SL("_putCache"), &put);
	}
	if (notAllowEmpty) {
		ZVAL_BOOL(&_5, 1);
	} else {
		ZVAL_BOOL(&_5, 0);
	}
	if (noRecursive) {
		ZVAL_BOOL(&_6, 1);
	} else {
		ZVAL_BOOL(&_6, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 207, &put, &name, filters, defaultValue, &_5, &_6);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets variable from $_GET superglobal applying filters if needed
 * If no parameters are given the $_GET superglobal is returned
 *
 *<code>
 * // Returns value from $_GET["id"] without sanitizing
 * $id = $request->getQuery("id");
 *
 * // Returns value from $_GET["id"] with sanitizing
 * $id = $request->getQuery("id", "int");
 *
 * // Returns value from $_GET["id"] with a default value
 * $id = $request->getQuery("id", null, 150);
 *</code>
 */
PHP_METHOD(Phalcon_Http_Request, getQuery) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive;
	zval *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, _GET, __$null, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_GET);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));
	zephir_fetch_params(1, 0, 5, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
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
	}
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		notAllowEmpty = zephir_get_boolval(notAllowEmpty_param);
	}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	if (notAllowEmpty) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	if (noRecursive) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethelper", NULL, 207, &_GET, &name, filters, defaultValue, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Helper to get data from superglobals, applying filters if needed.
 * If no parameters are given the superglobal is returned.
 */
PHP_METHOD(Phalcon_Http_Request, getHelper) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool notAllowEmpty, noRecursive, _5;
	zval name;
	zval *source_param = NULL, *name_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *notAllowEmpty_param = NULL, *noRecursive_param = NULL, __$null, value, filter, dependencyInjector, _0$$6, _1$$6, _2$$6, _3$$5, _4$$5;
	zval source;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&_0$$6);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 5, &source_param, &name_param, &filters, &defaultValue, &notAllowEmpty_param, &noRecursive_param);

	zephir_get_arrval(&source, source_param);
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
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
	}
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!notAllowEmpty_param) {
		notAllowEmpty = 0;
	} else {
		notAllowEmpty = zephir_get_boolval(notAllowEmpty_param);
	}
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		noRecursive = zephir_get_boolval(noRecursive_param);
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(&name, "")) {
		RETURN_CTOR(&source);
	}
	ZEPHIR_OBS_VAR(&value);
	if (!(zephir_array_isset_fetch(&value, &source, &name, 0))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(filters) != IS_NULL) {
		ZEPHIR_OBS_VAR(&filter);
		zephir_read_property(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
		if (Z_TYPE_P(&filter) != IS_OBJECT) {
			zephir_read_property(&_0$$6, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&dependencyInjector, &_0$$6);
			if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service", "phalcon/http/request.zep", 192);
				return;
			}
			ZEPHIR_INIT_VAR(&_2$$6);
			ZVAL_STRING(&_2$$6, "filter");
			ZEPHIR_CALL_METHOD(&_1$$6, &dependencyInjector, "getshared", NULL, 0, &_2$$6);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&filter, &_1$$6);
			zephir_update_property_zval(this_ptr, SL("_filter"), &filter);
		}
		if (noRecursive) {
			ZVAL_BOOL(&_4$$5, 1);
		} else {
			ZVAL_BOOL(&_4$$5, 0);
		}
		ZEPHIR_CALL_METHOD(&_3$$5, &filter, "sanitize", NULL, 0, &value, filters, &_4$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&value, &_3$$5);
	}
	_5 = ZEPHIR_IS_EMPTY(&value);
	if (_5) {
		_5 = notAllowEmpty == 1;
	}
	if (_5) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_CCTOR(&value);

}

/**
 * Gets variable from $_SERVER superglobal
 */
PHP_METHOD(Phalcon_Http_Request, getServer) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, _SERVER, serverValue;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&serverValue);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 1, 0, &name_param);

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


	if (zephir_array_isset_fetch(&serverValue, &_SERVER, &name, 1)) {
		RETURN_CTOR(&serverValue);
	}
	RETURN_MM_NULL();

}

/**
 * Checks whether $_REQUEST superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, _REQUEST;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_REQUEST);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	zephir_fetch_params(1, 1, 0, &name_param);

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


	RETURN_MM_BOOL(zephir_array_isset(&_REQUEST, &name));

}

/**
 * Checks whether $_POST superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasPost) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, _POST;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_POST);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SL("_POST"));
	zephir_fetch_params(1, 1, 0, &name_param);

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


	RETURN_MM_BOOL(zephir_array_isset(&_POST, &name));

}

/**
 * Checks whether the PUT data has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasPut) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, put;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&put);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

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


	ZEPHIR_CALL_METHOD(&put, this_ptr, "getput", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_array_isset(&put, &name));

}

/**
 * Checks whether $_GET superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasQuery) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, _GET;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_GET);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));
	zephir_fetch_params(1, 1, 0, &name_param);

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


	RETURN_MM_BOOL(zephir_array_isset(&_GET, &name));

}

/**
 * Checks whether $_SERVER superglobal has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasServer) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, _SERVER;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_SERVER);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 1, 0, &name_param);

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


	RETURN_MM_BOOL(zephir_array_isset(&_SERVER, &name));

}

/**
 * Checks whether headers has certain index
 */
PHP_METHOD(Phalcon_Http_Request, hasHeader) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *header_param = NULL, _SERVER, name, _0, _1, _2, _3;
	zval header;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 1, 0, &header_param);

	if (UNEXPECTED(Z_TYPE_P(header_param) != IS_STRING && Z_TYPE_P(header_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'header' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(header_param) == IS_STRING)) {
		zephir_get_strval(&header, header_param);
	} else {
		ZEPHIR_INIT_VAR(&header);
		ZVAL_EMPTY_STRING(&header);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "-");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "_");
	ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 22, &header, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	zephir_fast_strtoupper(&name, &_2);
	if (zephir_array_isset(&_SERVER, &name)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SV(&_3, "HTTP_", &name);
	if (zephir_array_isset(&_SERVER, &_3)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Gets HTTP header from request data
 */
PHP_METHOD(Phalcon_Http_Request, getHeader) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *header_param = NULL, _SERVER, value, name, _0, _1, _2, _3;
	zval header;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 1, 0, &header_param);

	if (UNEXPECTED(Z_TYPE_P(header_param) != IS_STRING && Z_TYPE_P(header_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'header' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(header_param) == IS_STRING)) {
		zephir_get_strval(&header, header_param);
	} else {
		ZEPHIR_INIT_VAR(&header);
		ZVAL_EMPTY_STRING(&header);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "-");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "_");
	ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 22, &header, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	zephir_fast_strtoupper(&name, &_2);
	ZEPHIR_OBS_VAR(&value);
	if (zephir_array_isset_fetch(&value, &_SERVER, &name, 0)) {
		RETURN_CCTOR(&value);
	}
	ZEPHIR_OBS_NVAR(&value);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SV(&_3, "HTTP_", &name);
	if (zephir_array_isset_fetch(&value, &_SERVER, &_3, 0)) {
		RETURN_CCTOR(&value);
	}
	RETURN_MM_STRING("");

}

/**
 * Gets HTTP schema (http/https)
 */
PHP_METHOD(Phalcon_Http_Request, getScheme) {

	zval https, scheme, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&https);
	ZVAL_UNDEF(&scheme);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTPS");
	ZEPHIR_CALL_METHOD(&https, this_ptr, "getserver", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&https)) {
		ZEPHIR_INIT_VAR(&scheme);
		if (ZEPHIR_IS_STRING(&https, "off")) {
			ZVAL_STRING(&scheme, "http");
		} else {
			ZVAL_STRING(&scheme, "https");
		}
	} else {
		ZEPHIR_INIT_NVAR(&scheme);
		ZVAL_STRING(&scheme, "http");
	}
	RETURN_CCTOR(&scheme);

}

/**
 * Checks whether request has been made using ajax
 */
PHP_METHOD(Phalcon_Http_Request, isAjax) {

	zend_bool _0;
	zval _SERVER, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_1);

	zephir_get_global(&_SERVER, SL("_SERVER"));

	_0 = zephir_array_isset_string(&_SERVER, SL("HTTP_X_REQUESTED_WITH"));
	if (_0) {
		zephir_array_fetch_string(&_1, &_SERVER, SL("HTTP_X_REQUESTED_WITH"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 330);
		_0 = ZEPHIR_IS_STRING_IDENTICAL(&_1, "XMLHttpRequest");
	}
	RETURN_BOOL(_0);

}

/**
 * Checks whether request has been made using SOAP
 */
PHP_METHOD(Phalcon_Http_Request, isSoap) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _SERVER, contentType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&contentType);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (zephir_array_isset_string(&_SERVER, SL("HTTP_SOAPACTION"))) {
		RETURN_MM_BOOL(1);
	} else {
		ZEPHIR_CALL_METHOD(&contentType, this_ptr, "getcontenttype", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&contentType))) {
			RETURN_MM_BOOL(zephir_memnstr_str(&contentType, SL("application/soap+xml"), "phalcon/http/request.zep", 345));
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Alias of isSoap(). It will be deprecated in future versions
 */
PHP_METHOD(Phalcon_Http_Request, isSoapRequested) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "issoap", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Checks whether request has been made using any secure layer
 */
PHP_METHOD(Phalcon_Http_Request, isSecure) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getscheme", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "https"));

}

/**
 * Alias of isSecure(). It will be deprecated in future versions
 */
PHP_METHOD(Phalcon_Http_Request, isSecureRequest) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "issecure", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets HTTP raw request body
 */
PHP_METHOD(Phalcon_Http_Request, getRawBody) {

	zval rawBody, contents, _0$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawBody);
	ZVAL_UNDEF(&contents);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&rawBody);
	zephir_read_property(&rawBody, this_ptr, SL("_rawBody"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&rawBody)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "php://input");
		ZEPHIR_INIT_VAR(&contents);
		zephir_file_get_contents(&contents, &_0$$3);
		zephir_update_property_zval(this_ptr, SL("_rawBody"), &contents);
		RETURN_CCTOR(&contents);
	}
	RETURN_CCTOR(&rawBody);

}

/**
 * Gets decoded JSON HTTP raw request body
 */
PHP_METHOD(Phalcon_Http_Request, getJsonRawBody) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *associative_param = NULL, rawBody, data, _0, _1;
	zend_bool associative;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawBody);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &associative_param);

	if (!associative_param) {
		associative = 0;
	} else {
		associative = zephir_get_boolval(associative_param);
	}


	ZEPHIR_CALL_METHOD(&rawBody, this_ptr, "getrawbody", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&rawBody)) {
		RETURN_MM_BOOL(0);
	}
	ZVAL_BOOL(&_0, (associative ? 1 : 0));
	ZEPHIR_INIT_VAR(&data);
	zephir_json_decode(&data, &rawBody, zephir_get_intval(&_0) );
	ZEPHIR_CALL_FUNCTION(&_1, "json_last_error", NULL, 210);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_1, 0)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_CCTOR(&data);

}

/**
 * Gets active server address IP
 */
PHP_METHOD(Phalcon_Http_Request, getServerAddress) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _SERVER, serverAddr, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&serverAddr);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_OBS_VAR(&serverAddr);
	if (zephir_array_isset_string_fetch(&serverAddr, &_SERVER, SL("SERVER_ADDR"), 0)) {
		RETURN_CCTOR(&serverAddr);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "localhost");
	ZEPHIR_RETURN_CALL_FUNCTION("gethostbyname", NULL, 211, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets active server name
 */
PHP_METHOD(Phalcon_Http_Request, getServerName) {

	zval _SERVER, serverName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&serverName);

	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (zephir_array_isset_string_fetch(&serverName, &_SERVER, SL("SERVER_NAME"), 1)) {
		RETURN_CTORW(&serverName);
	}
	RETURN_STRING("localhost");

}

/**
 * Gets host name used by the request.
 *
 * `Request::getHttpHost` trying to find host name in following order:
 *
 * - `$_SERVER["HTTP_HOST"]`
 * - `$_SERVER["SERVER_NAME"]`
 * - `$_SERVER["SERVER_ADDR"]`
 *
 * Optionally `Request::getHttpHost` validates and clean host name.
 * The `Request::$_strictHostCheck` can be used to validate host name.
 *
 * Note: validation and cleaning have a negative performance impact because
 * they use regular expressions.
 *
 * <code>
 * use Phalcon\Http\Request;
 *
 * $request = new Request;
 *
 * $_SERVER["HTTP_HOST"] = "example.com";
 * $request->getHttpHost(); // example.com
 *
 * $_SERVER["HTTP_HOST"] = "example.com:8080";
 * $request->getHttpHost(); // example.com:8080
 *
 * $request->setStrictHostCheck(true);
 * $_SERVER["HTTP_HOST"] = "ex=am~ple.com";
 * $request->getHttpHost(); // UnexpectedValueException
 *
 * $_SERVER["HTTP_HOST"] = "ExAmPlE.com";
 * $request->getHttpHost(); // example.com
 * </code>
 */
PHP_METHOD(Phalcon_Http_Request, getHttpHost) {

	zval _14;
	zend_bool _3;
	zval host, strict, _0, _1$$3, _2$$4, _4$$5, _8$$5, _9$$5, _10$$5, _11$$5, _5$$6, _6$$6, _7$$6, _12$$7, _13$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&strict);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&strict);
	zephir_read_property(&strict, this_ptr, SL("_strictHostCheck"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_HOST");
	ZEPHIR_CALL_METHOD(&host, this_ptr, "getserver", NULL, 0, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(&host))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "SERVER_NAME");
		ZEPHIR_CALL_METHOD(&host, this_ptr, "getserver", NULL, 0, &_1$$3);
		zephir_check_call_status();
		if (!(zephir_is_true(&host))) {
			ZEPHIR_INIT_VAR(&_2$$4);
			ZVAL_STRING(&_2$$4, "SERVER_ADDR");
			ZEPHIR_CALL_METHOD(&host, this_ptr, "getserver", NULL, 0, &_2$$4);
			zephir_check_call_status();
		}
	}
	_3 = zephir_is_true(&host);
	if (_3) {
		_3 = zephir_is_true(&strict);
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&_4$$5);
		zephir_fast_trim(&_4$$5, &host, NULL , ZEPHIR_TRIM_BOTH);
		ZEPHIR_INIT_NVAR(&host);
		zephir_fast_strtolower(&host, &_4$$5);
		if (zephir_memnstr_str(&host, SL(":"), "phalcon/http/request.zep", 507)) {
			ZEPHIR_INIT_VAR(&_5$$6);
			ZVAL_STRING(&_5$$6, "/:[[:digit:]]+$/");
			ZEPHIR_INIT_VAR(&_6$$6);
			ZVAL_STRING(&_6$$6, "");
			ZEPHIR_CALL_FUNCTION(&_7$$6, "preg_replace", NULL, 35, &_5$$6, &_6$$6, &host);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&host, &_7$$6);
		}
		ZEPHIR_INIT_VAR(&_8$$5);
		ZVAL_STRING(&_8$$5, "/[a-z0-9-]+\\.?/");
		ZEPHIR_INIT_VAR(&_9$$5);
		ZVAL_STRING(&_9$$5, "");
		ZEPHIR_CALL_FUNCTION(&_10$$5, "preg_replace", NULL, 35, &_8$$5, &_9$$5, &host);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_11$$5);
		ZVAL_STRING(&_11$$5, "");
		if (!ZEPHIR_IS_IDENTICAL(&_11$$5, &_10$$5)) {
			ZEPHIR_INIT_VAR(&_12$$7);
			object_init_ex(&_12$$7, spl_ce_UnexpectedValueException);
			ZEPHIR_INIT_VAR(&_13$$7);
			ZEPHIR_CONCAT_SV(&_13$$7, "Invalid host ", &host);
			ZEPHIR_CALL_METHOD(NULL, &_12$$7, "__construct", NULL, 212, &_13$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_12$$7, "phalcon/http/request.zep", 516);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_get_strval(&_14, &host);
	RETURN_CTOR(&_14);

}

/**
 * Sets if the `Request::getHttpHost` method must be use strict validation of host name or not
 */
PHP_METHOD(Phalcon_Http_Request, setStrictHostCheck) {

	zval *flag_param = NULL, __$true, __$false;
	zend_bool flag;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(0, 1, &flag_param);

	if (!flag_param) {
		flag = 1;
	} else {
		flag = zephir_get_boolval(flag_param);
	}


	if (flag) {
		zephir_update_property_zval(this_ptr, SL("_strictHostCheck"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_strictHostCheck"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Checks if the `Request::getHttpHost` method will be use strict validation of host name or not
 */
PHP_METHOD(Phalcon_Http_Request, isStrictHostCheck) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_strictHostCheck");

}

/**
 * Gets information about the port on which the request is made.
 */
PHP_METHOD(Phalcon_Http_Request, getPort) {

	zval host, pos, _0, _7, _1$$4, _2$$5, _3$$5, _4$$3, _5$$3, _6$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_HOST");
	ZEPHIR_CALL_METHOD(&host, this_ptr, "getserver", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&host)) {
		if (zephir_memnstr_str(&host, SL(":"), "phalcon/http/request.zep", 553)) {
			ZEPHIR_INIT_VAR(&_1$$4);
			ZVAL_STRING(&_1$$4, ":");
			ZEPHIR_CALL_FUNCTION(&pos, "strrpos", NULL, 141, &host, &_1$$4);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&pos)) {
				ZVAL_LONG(&_2$$5, (zephir_get_numberval(&pos) + 1));
				ZEPHIR_INIT_VAR(&_3$$5);
				zephir_substr(&_3$$5, &host, zephir_get_intval(&_2$$5), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				RETURN_MM_LONG(zephir_get_intval(&_3$$5));
			}
		}
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "getscheme", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "https");
		if (ZEPHIR_IS_IDENTICAL(&_6$$3, &_5$$3)) {
			ZVAL_LONG(&_4$$3, 443);
		} else {
			ZVAL_LONG(&_4$$3, 80);
		}
		RETURN_CCTOR(&_4$$3);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "SERVER_PORT");
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getserver", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_get_intval(&_7));

}

/**
 * Gets HTTP URI which request has been made
 */
PHP_METHOD(Phalcon_Http_Request, getURI) {

	zval _SERVER, requestURI;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&requestURI);

	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (zephir_array_isset_string_fetch(&requestURI, &_SERVER, SL("REQUEST_URI"), 1)) {
		RETURN_CTORW(&requestURI);
	}
	RETURN_STRING("");

}

/**
 * Gets most possible client IPv4 Address. This method searches in
 * $_SERVER["REMOTE_ADDR"] and optionally in $_SERVER["HTTP_X_FORWARDED_FOR"]
 */
PHP_METHOD(Phalcon_Http_Request, getClientAddress) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *trustForwardedHeader_param = NULL, _SERVER, address, _0$$7, _1$$7;
	zend_bool trustForwardedHeader;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&address);
	ZVAL_UNDEF(&_0$$7);
	ZVAL_UNDEF(&_1$$7);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 0, 1, &trustForwardedHeader_param);

	if (!trustForwardedHeader_param) {
		trustForwardedHeader = 0;
	} else {
		trustForwardedHeader = zephir_get_boolval(trustForwardedHeader_param);
	}


	ZEPHIR_INIT_VAR(&address);
	ZVAL_NULL(&address);
	if (trustForwardedHeader) {
		ZEPHIR_OBS_NVAR(&address);
		zephir_array_isset_string_fetch(&address, &_SERVER, SL("HTTP_X_FORWARDED_FOR"), 0);
		if (Z_TYPE_P(&address) == IS_NULL) {
			ZEPHIR_OBS_NVAR(&address);
			zephir_array_isset_string_fetch(&address, &_SERVER, SL("HTTP_CLIENT_IP"), 0);
		}
	}
	if (Z_TYPE_P(&address) == IS_NULL) {
		ZEPHIR_OBS_NVAR(&address);
		zephir_array_isset_string_fetch(&address, &_SERVER, SL("REMOTE_ADDR"), 0);
	}
	if (Z_TYPE_P(&address) == IS_STRING) {
		if (zephir_memnstr_str(&address, SL(","), "phalcon/http/request.zep", 604)) {
			ZEPHIR_INIT_VAR(&_0$$7);
			zephir_fast_explode_str(&_0$$7, SL(","), &address, LONG_MAX);
			zephir_array_fetch_long(&_1$$7, &_0$$7, 0, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 608);
			RETURN_CTOR(&_1$$7);
		}
		RETURN_CCTOR(&address);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Gets HTTP method which request has been made
 *
 * If the X-HTTP-Method-Override header is set, and if the method is a POST,
 * then it is used to determine the "real" intended HTTP method.
 *
 * The _method request parameter can also be used to determine the HTTP method,
 * but only if setHttpMethodParameterOverride(true) has been called.
 *
 * The method is always an uppercased string.
 */
PHP_METHOD(Phalcon_Http_Request, getMethod) {

	zval returnMethod;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _SERVER, _REQUEST, overridedMethod, spoofedMethod, requestMethod, _0, _3, _1$$5, _2$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_REQUEST);
	ZVAL_UNDEF(&overridedMethod);
	ZVAL_UNDEF(&spoofedMethod);
	ZVAL_UNDEF(&requestMethod);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&returnMethod);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_INIT_VAR(&returnMethod);
	ZVAL_STRING(&returnMethod, "");
	ZEPHIR_OBS_VAR(&requestMethod);
	if (EXPECTED(zephir_array_isset_string_fetch(&requestMethod, &_SERVER, SL("REQUEST_METHOD"), 0))) {
		ZEPHIR_INIT_NVAR(&returnMethod);
		zephir_fast_strtoupper(&returnMethod, &requestMethod);
	} else {
		RETURN_MM_STRING("GET");
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "POST");
	if (ZEPHIR_IS_IDENTICAL(&_0, &returnMethod)) {
		ZEPHIR_INIT_VAR(&_1$$5);
		ZVAL_STRING(&_1$$5, "X-HTTP-METHOD-OVERRIDE");
		ZEPHIR_CALL_METHOD(&overridedMethod, this_ptr, "getheader", NULL, 213, &_1$$5);
		zephir_check_call_status();
		zephir_read_property(&_2$$5, this_ptr, SL("_httpMethodParameterOverride"), PH_NOISY_CC | PH_READONLY);
		if (!(ZEPHIR_IS_EMPTY(&overridedMethod))) {
			ZEPHIR_INIT_NVAR(&returnMethod);
			zephir_fast_strtoupper(&returnMethod, &overridedMethod);
		} else if (zephir_is_true(&_2$$5)) {
			ZEPHIR_OBS_VAR(&spoofedMethod);
			if (zephir_array_isset_string_fetch(&spoofedMethod, &_REQUEST, SL("_method"), 0)) {
				ZEPHIR_INIT_NVAR(&returnMethod);
				zephir_fast_strtoupper(&returnMethod, &spoofedMethod);
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "isvalidhttpmethod", NULL, 0, &returnMethod);
	zephir_check_call_status();
	if (!(zephir_is_true(&_3))) {
		RETURN_MM_STRING("GET");
	}
	RETURN_CTOR(&returnMethod);

}

/**
 * Gets HTTP user agent used to made the request
 */
PHP_METHOD(Phalcon_Http_Request, getUserAgent) {

	zval _SERVER, userAgent;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&userAgent);

	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (zephir_array_isset_string_fetch(&userAgent, &_SERVER, SL("HTTP_USER_AGENT"), 1)) {
		RETURN_CTORW(&userAgent);
	}
	RETURN_STRING("");

}

/**
 * Checks if a method is a valid HTTP method
 */
PHP_METHOD(Phalcon_Http_Request, isValidHttpMethod) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *method_param = NULL, _0;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method_param);

	zephir_get_strval(&method, method_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtoupper(&_0, &method);
	do {
		if (ZEPHIR_IS_STRING(&_0, "GET") || ZEPHIR_IS_STRING(&_0, "POST") || ZEPHIR_IS_STRING(&_0, "PUT") || ZEPHIR_IS_STRING(&_0, "DELETE") || ZEPHIR_IS_STRING(&_0, "HEAD") || ZEPHIR_IS_STRING(&_0, "OPTIONS") || ZEPHIR_IS_STRING(&_0, "PATCH") || ZEPHIR_IS_STRING(&_0, "PURGE") || ZEPHIR_IS_STRING(&_0, "TRACE") || ZEPHIR_IS_STRING(&_0, "CONNECT")) {
			RETURN_MM_BOOL(1);
		}
	} while(0);

	RETURN_MM_BOOL(0);

}

/**
 * Check if HTTP method match any of the passed methods
 * When strict is true it checks if validated methods are real HTTP methods
 */
PHP_METHOD(Phalcon_Http_Request, isMethod) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool strict, _0$$3;
	zval *methods, methods_sub, *strict_param = NULL, httpMethod, method, _1$$3, _2$$4, _3$$4, *_4$$5, _5$$5, _6$$6, _7$$6, _9$$8, _10$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&methods_sub);
	ZVAL_UNDEF(&httpMethod);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &methods, &strict_param);

	if (!strict_param) {
		strict = 0;
	} else {
		strict = zephir_get_boolval(strict_param);
	}


	ZEPHIR_CALL_METHOD(&httpMethod, this_ptr, "getmethod", NULL, 214);
	zephir_check_call_status();
	if (Z_TYPE_P(methods) == IS_STRING) {
		_0$$3 = strict;
		if (_0$$3) {
			ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "isvalidhttpmethod", NULL, 0, methods);
			zephir_check_call_status();
			_0$$3 = !zephir_is_true(&_1$$3);
		}
		if (_0$$3) {
			ZEPHIR_INIT_VAR(&_2$$4);
			object_init_ex(&_2$$4, phalcon_http_request_exception_ce);
			ZEPHIR_INIT_VAR(&_3$$4);
			ZEPHIR_CONCAT_SV(&_3$$4, "Invalid HTTP method: ", methods);
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 4, &_3$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$4, "phalcon/http/request.zep", 703);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(methods, &httpMethod));
	}
	if (Z_TYPE_P(methods) == IS_ARRAY) {
		zephir_is_iterable(methods, 0, "phalcon/http/request.zep", 715);
		if (Z_TYPE_P(methods) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(methods), _4$$5)
			{
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_COPY(&method, _4$$5);
				if (strict) {
					ZVAL_BOOL(&_7$$6, 1);
				} else {
					ZVAL_BOOL(&_7$$6, 0);
				}
				ZEPHIR_CALL_METHOD(&_6$$6, this_ptr, "ismethod", &_8, 215, &method, &_7$$6);
				zephir_check_call_status();
				if (zephir_is_true(&_6$$6)) {
					RETURN_MM_BOOL(1);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, methods, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$5, methods, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&method, methods, "current", NULL, 0);
				zephir_check_call_status();
					if (strict) {
						ZVAL_BOOL(&_10$$8, 1);
					} else {
						ZVAL_BOOL(&_10$$8, 0);
					}
					ZEPHIR_CALL_METHOD(&_9$$8, this_ptr, "ismethod", &_8, 215, &method, &_10$$8);
					zephir_check_call_status();
					if (zephir_is_true(&_9$$8)) {
						RETURN_MM_BOOL(1);
					}
				ZEPHIR_CALL_METHOD(NULL, methods, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&method);
		RETURN_MM_BOOL(0);
	}
	if (strict) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_request_exception_ce, "Invalid HTTP method: non-string", "phalcon/http/request.zep", 719);
		return;
	}
	RETURN_MM_BOOL(0);

}

/**
 * Checks whether HTTP method is POST. if _SERVER["REQUEST_METHOD"]==="POST"
 */
PHP_METHOD(Phalcon_Http_Request, isPost) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 214);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "POST"));

}

/**
 * Checks whether HTTP method is GET. if _SERVER["REQUEST_METHOD"]==="GET"
 */
PHP_METHOD(Phalcon_Http_Request, isGet) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 214);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "GET"));

}

/**
 * Checks whether HTTP method is PUT. if _SERVER["REQUEST_METHOD"]==="PUT"
 */
PHP_METHOD(Phalcon_Http_Request, isPut) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 214);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "PUT"));

}

/**
 * Checks whether HTTP method is PATCH. if _SERVER["REQUEST_METHOD"]==="PATCH"
 */
PHP_METHOD(Phalcon_Http_Request, isPatch) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 214);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "PATCH"));

}

/**
 * Checks whether HTTP method is HEAD. if _SERVER["REQUEST_METHOD"]==="HEAD"
 */
PHP_METHOD(Phalcon_Http_Request, isHead) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 214);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "HEAD"));

}

/**
 * Checks whether HTTP method is DELETE. if _SERVER["REQUEST_METHOD"]==="DELETE"
 */
PHP_METHOD(Phalcon_Http_Request, isDelete) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 214);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "DELETE"));

}

/**
 * Checks whether HTTP method is OPTIONS. if _SERVER["REQUEST_METHOD"]==="OPTIONS"
 */
PHP_METHOD(Phalcon_Http_Request, isOptions) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 214);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "OPTIONS"));

}

/**
 * Checks whether HTTP method is PURGE (Squid and Varnish support). if _SERVER["REQUEST_METHOD"]==="PURGE"
 */
PHP_METHOD(Phalcon_Http_Request, isPurge) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 214);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "PURGE"));

}

/**
 * Checks whether HTTP method is TRACE. if _SERVER["REQUEST_METHOD"]==="TRACE"
 */
PHP_METHOD(Phalcon_Http_Request, isTrace) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 214);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "TRACE"));

}

/**
 * Checks whether HTTP method is CONNECT. if _SERVER["REQUEST_METHOD"]==="CONNECT"
 */
PHP_METHOD(Phalcon_Http_Request, isConnect) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 214);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "CONNECT"));

}

/**
 * Checks whether request include attached files
 */
PHP_METHOD(Phalcon_Http_Request, hasFiles) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberFiles;
	zval *onlySuccessful_param = NULL, _FILES, files, file, error, *_0, _1, _3$$8, _4$$8, _7$$13, _8$$13;
	zend_bool onlySuccessful, _2$$6, _6$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_7$$13);
	ZVAL_UNDEF(&_8$$13);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_fetch_params(1, 0, 1, &onlySuccessful_param);

	if (!onlySuccessful_param) {
		onlySuccessful = 0;
	} else {
		onlySuccessful = zephir_get_boolval(onlySuccessful_param);
	}


	numberFiles = 0;
	ZEPHIR_CPY_WRT(&files, &_FILES);
	if (Z_TYPE_P(&files) != IS_ARRAY) {
		RETURN_MM_LONG(0);
	}
	zephir_is_iterable(&files, 0, "phalcon/http/request.zep", 834);
	if (Z_TYPE_P(&files) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&files), _0)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _0);
			ZEPHIR_OBS_NVAR(&error);
			if (zephir_array_isset_string_fetch(&error, &file, SL("error"), 0)) {
				if (Z_TYPE_P(&error) != IS_ARRAY) {
					_2$$6 = !zephir_is_true(&error);
					if (!(_2$$6)) {
						_2$$6 = !onlySuccessful;
					}
					if (_2$$6) {
						numberFiles++;
					}
				}
				if (Z_TYPE_P(&error) == IS_ARRAY) {
					if (onlySuccessful) {
						ZVAL_BOOL(&_4$$8, 1);
					} else {
						ZVAL_BOOL(&_4$$8, 0);
					}
					ZEPHIR_CALL_METHOD(&_3$$8, this_ptr, "hasfilehelper", &_5, 216, &error, &_4$$8);
					zephir_check_call_status();
					numberFiles += zephir_get_numberval(&_3$$8);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &files, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &files, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&file, &files, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&error);
				if (zephir_array_isset_string_fetch(&error, &file, SL("error"), 0)) {
					if (Z_TYPE_P(&error) != IS_ARRAY) {
						_6$$11 = !zephir_is_true(&error);
						if (!(_6$$11)) {
							_6$$11 = !onlySuccessful;
						}
						if (_6$$11) {
							numberFiles++;
						}
					}
					if (Z_TYPE_P(&error) == IS_ARRAY) {
						if (onlySuccessful) {
							ZVAL_BOOL(&_8$$13, 1);
						} else {
							ZVAL_BOOL(&_8$$13, 0);
						}
						ZEPHIR_CALL_METHOD(&_7$$13, this_ptr, "hasfilehelper", &_5, 216, &error, &_8$$13);
						zephir_check_call_status();
						numberFiles += zephir_get_numberval(&_7$$13);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &files, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&file);
	RETURN_MM_LONG(numberFiles);

}

/**
 * Recursively counts file in an array of files
 */
PHP_METHOD(Phalcon_Http_Request, hasFileHelper) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberFiles;
	zend_bool onlySuccessful, _2$$5, _6$$9;
	zval *data, data_sub, *onlySuccessful_param = NULL, value, *_0, _1, _3$$7, _4$$7, _7$$11, _8$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data, &onlySuccessful_param);

	onlySuccessful = zephir_get_boolval(onlySuccessful_param);


	numberFiles = 0;
	if (Z_TYPE_P(data) != IS_ARRAY) {
		RETURN_MM_LONG(1);
	}
	zephir_is_iterable(data, 0, "phalcon/http/request.zep", 861);
	if (Z_TYPE_P(data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(data), _0)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (Z_TYPE_P(&value) != IS_ARRAY) {
				_2$$5 = !zephir_is_true(&value);
				if (!(_2$$5)) {
					_2$$5 = !onlySuccessful;
				}
				if (_2$$5) {
					numberFiles++;
				}
			}
			if (Z_TYPE_P(&value) == IS_ARRAY) {
				if (onlySuccessful) {
					ZVAL_BOOL(&_4$$7, 1);
				} else {
					ZVAL_BOOL(&_4$$7, 0);
				}
				ZEPHIR_CALL_METHOD(&_3$$7, this_ptr, "hasfilehelper", &_5, 216, &value, &_4$$7);
				zephir_check_call_status();
				numberFiles += zephir_get_numberval(&_3$$7);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, data, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&value) != IS_ARRAY) {
					_6$$9 = !zephir_is_true(&value);
					if (!(_6$$9)) {
						_6$$9 = !onlySuccessful;
					}
					if (_6$$9) {
						numberFiles++;
					}
				}
				if (Z_TYPE_P(&value) == IS_ARRAY) {
					if (onlySuccessful) {
						ZVAL_BOOL(&_8$$11, 1);
					} else {
						ZVAL_BOOL(&_8$$11, 0);
					}
					ZEPHIR_CALL_METHOD(&_7$$11, this_ptr, "hasfilehelper", &_5, 216, &value, &_8$$11);
					zephir_check_call_status();
					numberFiles += zephir_get_numberval(&_7$$11);
				}
			ZEPHIR_CALL_METHOD(NULL, data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	RETURN_MM_LONG(numberFiles);

}

/**
 * Gets attached files as Phalcon\Http\Request\File instances
 */
PHP_METHOD(Phalcon_Http_Request, getUploadedFiles) {

	zend_string *_3$$3;
	zend_ulong _2$$3;
	zval files;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *onlySuccessful_param = NULL, _FILES, superFiles, prefix, input, smoothInput, file, dataFile, *_0$$3, _1$$3, _4$$4, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5, *_11$$5, _12$$5, _14$$6, _15$$7, _16$$7, _17$$7, _20$$8, _21$$9, _22$$9, _23$$9, _24$$9, _26$$10, _27$$11, _28$$12, _29$$13, _30$$13, _31$$13, _32$$13, _33$$13, *_34$$13, _35$$13, _37$$14, _38$$15, _39$$15, _40$$15, _41$$15, _43$$16, _44$$17, _45$$17, _46$$17, _47$$17, _49$$18, _50$$19;
	zend_bool onlySuccessful, _13$$6, _19$$8, _25$$10, _36$$14, _42$$16, _48$$18;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&superFiles);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&smoothInput);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&dataFile);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_27$$11);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_37$$14);
	ZVAL_UNDEF(&_38$$15);
	ZVAL_UNDEF(&_39$$15);
	ZVAL_UNDEF(&_40$$15);
	ZVAL_UNDEF(&_41$$15);
	ZVAL_UNDEF(&_43$$16);
	ZVAL_UNDEF(&_44$$17);
	ZVAL_UNDEF(&_45$$17);
	ZVAL_UNDEF(&_46$$17);
	ZVAL_UNDEF(&_47$$17);
	ZVAL_UNDEF(&_49$$18);
	ZVAL_UNDEF(&_50$$19);
	ZVAL_UNDEF(&files);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_fetch_params(1, 0, 1, &onlySuccessful_param);

	if (!onlySuccessful_param) {
		onlySuccessful = 0;
	} else {
		onlySuccessful = zephir_get_boolval(onlySuccessful_param);
	}


	ZEPHIR_INIT_VAR(&files);
	array_init(&files);
	ZEPHIR_CPY_WRT(&superFiles, &_FILES);
	if (zephir_fast_count_int(&superFiles) > 0) {
		zephir_is_iterable(&superFiles, 0, "phalcon/http/request.zep", 906);
		if (Z_TYPE_P(&superFiles) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&superFiles), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&prefix);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&prefix, _3$$3);
				} else {
					ZVAL_LONG(&prefix, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&input);
				ZVAL_COPY(&input, _0$$3);
				ZEPHIR_OBS_NVAR(&_4$$4);
				zephir_array_fetch_string(&_4$$4, &input, SL("name"), PH_NOISY, "phalcon/http/request.zep", 877);
				if (Z_TYPE_P(&_4$$4) == IS_ARRAY) {
					zephir_array_fetch_string(&_5$$5, &input, SL("name"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 879);
					zephir_array_fetch_string(&_6$$5, &input, SL("type"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 880);
					zephir_array_fetch_string(&_7$$5, &input, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 881);
					zephir_array_fetch_string(&_8$$5, &input, SL("size"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 882);
					zephir_array_fetch_string(&_9$$5, &input, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 883);
					ZEPHIR_CALL_METHOD(&smoothInput, this_ptr, "smoothfiles", &_10, 217, &_5$$5, &_6$$5, &_7$$5, &_8$$5, &_9$$5, &prefix);
					zephir_check_call_status();
					zephir_is_iterable(&smoothInput, 0, "phalcon/http/request.zep", 900);
					if (Z_TYPE_P(&smoothInput) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&smoothInput), _11$$5)
						{
							ZEPHIR_INIT_NVAR(&file);
							ZVAL_COPY(&file, _11$$5);
							_13$$6 = onlySuccessful == 0;
							if (!(_13$$6)) {
								zephir_array_fetch_string(&_14$$6, &file, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 888);
								_13$$6 = ZEPHIR_IS_LONG(&_14$$6, 0);
							}
							if (_13$$6) {
								ZEPHIR_INIT_NVAR(&dataFile);
								zephir_create_array(&dataFile, 5, 0);
								ZEPHIR_OBS_NVAR(&_15$$7);
								zephir_array_fetch_string(&_15$$7, &file, SL("name"), PH_NOISY, "phalcon/http/request.zep", 890);
								zephir_array_update_string(&dataFile, SL("name"), &_15$$7, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_15$$7);
								zephir_array_fetch_string(&_15$$7, &file, SL("type"), PH_NOISY, "phalcon/http/request.zep", 891);
								zephir_array_update_string(&dataFile, SL("type"), &_15$$7, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_15$$7);
								zephir_array_fetch_string(&_15$$7, &file, SL("tmp_name"), PH_NOISY, "phalcon/http/request.zep", 892);
								zephir_array_update_string(&dataFile, SL("tmp_name"), &_15$$7, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_15$$7);
								zephir_array_fetch_string(&_15$$7, &file, SL("size"), PH_NOISY, "phalcon/http/request.zep", 893);
								zephir_array_update_string(&dataFile, SL("size"), &_15$$7, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_15$$7);
								zephir_array_fetch_string(&_15$$7, &file, SL("error"), PH_NOISY, "phalcon/http/request.zep", 895);
								zephir_array_update_string(&dataFile, SL("error"), &_15$$7, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_16$$7);
								object_init_ex(&_16$$7, phalcon_http_request_file_ce);
								zephir_array_fetch_string(&_17$$7, &file, SL("key"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 897);
								ZEPHIR_CALL_METHOD(NULL, &_16$$7, "__construct", &_18, 218, &dataFile, &_17$$7);
								zephir_check_call_status();
								zephir_array_append(&files, &_16$$7, PH_SEPARATE, "phalcon/http/request.zep", 897);
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &smoothInput, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_12$$5, &smoothInput, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_12$$5)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&file, &smoothInput, "current", NULL, 0);
							zephir_check_call_status();
								_19$$8 = onlySuccessful == 0;
								if (!(_19$$8)) {
									zephir_array_fetch_string(&_20$$8, &file, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 888);
									_19$$8 = ZEPHIR_IS_LONG(&_20$$8, 0);
								}
								if (_19$$8) {
									ZEPHIR_INIT_NVAR(&_21$$9);
									zephir_create_array(&_21$$9, 5, 0);
									ZEPHIR_OBS_NVAR(&_22$$9);
									zephir_array_fetch_string(&_22$$9, &file, SL("name"), PH_NOISY, "phalcon/http/request.zep", 890);
									zephir_array_update_string(&_21$$9, SL("name"), &_22$$9, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_22$$9);
									zephir_array_fetch_string(&_22$$9, &file, SL("type"), PH_NOISY, "phalcon/http/request.zep", 891);
									zephir_array_update_string(&_21$$9, SL("type"), &_22$$9, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_22$$9);
									zephir_array_fetch_string(&_22$$9, &file, SL("tmp_name"), PH_NOISY, "phalcon/http/request.zep", 892);
									zephir_array_update_string(&_21$$9, SL("tmp_name"), &_22$$9, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_22$$9);
									zephir_array_fetch_string(&_22$$9, &file, SL("size"), PH_NOISY, "phalcon/http/request.zep", 893);
									zephir_array_update_string(&_21$$9, SL("size"), &_22$$9, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_22$$9);
									zephir_array_fetch_string(&_22$$9, &file, SL("error"), PH_NOISY, "phalcon/http/request.zep", 895);
									zephir_array_update_string(&_21$$9, SL("error"), &_22$$9, PH_COPY | PH_SEPARATE);
									ZEPHIR_CPY_WRT(&dataFile, &_21$$9);
									ZEPHIR_INIT_NVAR(&_23$$9);
									object_init_ex(&_23$$9, phalcon_http_request_file_ce);
									zephir_array_fetch_string(&_24$$9, &file, SL("key"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 897);
									ZEPHIR_CALL_METHOD(NULL, &_23$$9, "__construct", &_18, 218, &dataFile, &_24$$9);
									zephir_check_call_status();
									zephir_array_append(&files, &_23$$9, PH_SEPARATE, "phalcon/http/request.zep", 897);
								}
							ZEPHIR_CALL_METHOD(NULL, &smoothInput, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&file);
				} else {
					_25$$10 = onlySuccessful == 0;
					if (!(_25$$10)) {
						zephir_array_fetch_string(&_26$$10, &input, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 901);
						_25$$10 = ZEPHIR_IS_LONG(&_26$$10, 0);
					}
					if (_25$$10) {
						ZEPHIR_INIT_NVAR(&_27$$11);
						object_init_ex(&_27$$11, phalcon_http_request_file_ce);
						ZEPHIR_CALL_METHOD(NULL, &_27$$11, "__construct", &_18, 218, &input, &prefix);
						zephir_check_call_status();
						zephir_array_append(&files, &_27$$11, PH_SEPARATE, "phalcon/http/request.zep", 902);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &superFiles, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &superFiles, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&prefix, &superFiles, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&input, &superFiles, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&_28$$12);
					zephir_array_fetch_string(&_28$$12, &input, SL("name"), PH_NOISY, "phalcon/http/request.zep", 877);
					if (Z_TYPE_P(&_28$$12) == IS_ARRAY) {
						zephir_array_fetch_string(&_29$$13, &input, SL("name"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 879);
						zephir_array_fetch_string(&_30$$13, &input, SL("type"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 880);
						zephir_array_fetch_string(&_31$$13, &input, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 881);
						zephir_array_fetch_string(&_32$$13, &input, SL("size"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 882);
						zephir_array_fetch_string(&_33$$13, &input, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 883);
						ZEPHIR_CALL_METHOD(&smoothInput, this_ptr, "smoothfiles", &_10, 217, &_29$$13, &_30$$13, &_31$$13, &_32$$13, &_33$$13, &prefix);
						zephir_check_call_status();
						zephir_is_iterable(&smoothInput, 0, "phalcon/http/request.zep", 900);
						if (Z_TYPE_P(&smoothInput) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&smoothInput), _34$$13)
							{
								ZEPHIR_INIT_NVAR(&file);
								ZVAL_COPY(&file, _34$$13);
								_36$$14 = onlySuccessful == 0;
								if (!(_36$$14)) {
									zephir_array_fetch_string(&_37$$14, &file, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 888);
									_36$$14 = ZEPHIR_IS_LONG(&_37$$14, 0);
								}
								if (_36$$14) {
									ZEPHIR_INIT_NVAR(&_38$$15);
									zephir_create_array(&_38$$15, 5, 0);
									ZEPHIR_OBS_NVAR(&_39$$15);
									zephir_array_fetch_string(&_39$$15, &file, SL("name"), PH_NOISY, "phalcon/http/request.zep", 890);
									zephir_array_update_string(&_38$$15, SL("name"), &_39$$15, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_39$$15);
									zephir_array_fetch_string(&_39$$15, &file, SL("type"), PH_NOISY, "phalcon/http/request.zep", 891);
									zephir_array_update_string(&_38$$15, SL("type"), &_39$$15, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_39$$15);
									zephir_array_fetch_string(&_39$$15, &file, SL("tmp_name"), PH_NOISY, "phalcon/http/request.zep", 892);
									zephir_array_update_string(&_38$$15, SL("tmp_name"), &_39$$15, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_39$$15);
									zephir_array_fetch_string(&_39$$15, &file, SL("size"), PH_NOISY, "phalcon/http/request.zep", 893);
									zephir_array_update_string(&_38$$15, SL("size"), &_39$$15, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_39$$15);
									zephir_array_fetch_string(&_39$$15, &file, SL("error"), PH_NOISY, "phalcon/http/request.zep", 895);
									zephir_array_update_string(&_38$$15, SL("error"), &_39$$15, PH_COPY | PH_SEPARATE);
									ZEPHIR_CPY_WRT(&dataFile, &_38$$15);
									ZEPHIR_INIT_NVAR(&_40$$15);
									object_init_ex(&_40$$15, phalcon_http_request_file_ce);
									zephir_array_fetch_string(&_41$$15, &file, SL("key"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 897);
									ZEPHIR_CALL_METHOD(NULL, &_40$$15, "__construct", &_18, 218, &dataFile, &_41$$15);
									zephir_check_call_status();
									zephir_array_append(&files, &_40$$15, PH_SEPARATE, "phalcon/http/request.zep", 897);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &smoothInput, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_35$$13, &smoothInput, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_35$$13)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&file, &smoothInput, "current", NULL, 0);
								zephir_check_call_status();
									_42$$16 = onlySuccessful == 0;
									if (!(_42$$16)) {
										zephir_array_fetch_string(&_43$$16, &file, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 888);
										_42$$16 = ZEPHIR_IS_LONG(&_43$$16, 0);
									}
									if (_42$$16) {
										ZEPHIR_INIT_NVAR(&_44$$17);
										zephir_create_array(&_44$$17, 5, 0);
										ZEPHIR_OBS_NVAR(&_45$$17);
										zephir_array_fetch_string(&_45$$17, &file, SL("name"), PH_NOISY, "phalcon/http/request.zep", 890);
										zephir_array_update_string(&_44$$17, SL("name"), &_45$$17, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&_45$$17);
										zephir_array_fetch_string(&_45$$17, &file, SL("type"), PH_NOISY, "phalcon/http/request.zep", 891);
										zephir_array_update_string(&_44$$17, SL("type"), &_45$$17, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&_45$$17);
										zephir_array_fetch_string(&_45$$17, &file, SL("tmp_name"), PH_NOISY, "phalcon/http/request.zep", 892);
										zephir_array_update_string(&_44$$17, SL("tmp_name"), &_45$$17, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&_45$$17);
										zephir_array_fetch_string(&_45$$17, &file, SL("size"), PH_NOISY, "phalcon/http/request.zep", 893);
										zephir_array_update_string(&_44$$17, SL("size"), &_45$$17, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&_45$$17);
										zephir_array_fetch_string(&_45$$17, &file, SL("error"), PH_NOISY, "phalcon/http/request.zep", 895);
										zephir_array_update_string(&_44$$17, SL("error"), &_45$$17, PH_COPY | PH_SEPARATE);
										ZEPHIR_CPY_WRT(&dataFile, &_44$$17);
										ZEPHIR_INIT_NVAR(&_46$$17);
										object_init_ex(&_46$$17, phalcon_http_request_file_ce);
										zephir_array_fetch_string(&_47$$17, &file, SL("key"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 897);
										ZEPHIR_CALL_METHOD(NULL, &_46$$17, "__construct", &_18, 218, &dataFile, &_47$$17);
										zephir_check_call_status();
										zephir_array_append(&files, &_46$$17, PH_SEPARATE, "phalcon/http/request.zep", 897);
									}
								ZEPHIR_CALL_METHOD(NULL, &smoothInput, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&file);
					} else {
						_48$$18 = onlySuccessful == 0;
						if (!(_48$$18)) {
							zephir_array_fetch_string(&_49$$18, &input, SL("error"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 901);
							_48$$18 = ZEPHIR_IS_LONG(&_49$$18, 0);
						}
						if (_48$$18) {
							ZEPHIR_INIT_NVAR(&_50$$19);
							object_init_ex(&_50$$19, phalcon_http_request_file_ce);
							ZEPHIR_CALL_METHOD(NULL, &_50$$19, "__construct", &_18, 218, &input, &prefix);
							zephir_check_call_status();
							zephir_array_append(&files, &_50$$19, PH_SEPARATE, "phalcon/http/request.zep", 902);
						}
					}
				ZEPHIR_CALL_METHOD(NULL, &superFiles, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&input);
		ZEPHIR_INIT_NVAR(&prefix);
	}
	RETURN_CTOR(&files);

}

/**
 * Smooth out $_FILES to have plain array with all files uploaded
 */
PHP_METHOD(Phalcon_Http_Request, smoothFiles) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval prefix;
	zval *names_param = NULL, *types_param = NULL, *tmp_names_param = NULL, *sizes_param = NULL, *errors_param = NULL, *prefix_param = NULL, idx, name, file, files, parentFiles, p, *_0, _1, _5$$4, _6$$5, _7$$5, _8$$5, _9$$5, _10$$5, *_12$$5, _13$$5, _15$$9, _16$$10, _17$$10, _18$$10, _19$$10, _20$$10, *_21$$10, _22$$10;
	zval names, types, tmp_names, sizes, errors, _4$$4, _14$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&names);
	ZVAL_UNDEF(&types);
	ZVAL_UNDEF(&tmp_names);
	ZVAL_UNDEF(&sizes);
	ZVAL_UNDEF(&errors);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&idx);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&parentFiles);
	ZVAL_UNDEF(&p);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&prefix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 6, 0, &names_param, &types_param, &tmp_names_param, &sizes_param, &errors_param, &prefix_param);

	ZEPHIR_OBS_COPY_OR_DUP(&names, names_param);
	ZEPHIR_OBS_COPY_OR_DUP(&types, types_param);
	ZEPHIR_OBS_COPY_OR_DUP(&tmp_names, tmp_names_param);
	ZEPHIR_OBS_COPY_OR_DUP(&sizes, sizes_param);
	ZEPHIR_OBS_COPY_OR_DUP(&errors, errors_param);
	zephir_get_strval(&prefix, prefix_param);


	ZEPHIR_INIT_VAR(&files);
	array_init(&files);
	zephir_is_iterable(&names, 0, "phalcon/http/request.zep", 951);
	if (Z_TYPE_P(&names) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&names), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&idx);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&idx, _3);
			} else {
				ZVAL_LONG(&idx, _2);
			}
			ZEPHIR_INIT_NVAR(&name);
			ZVAL_COPY(&name, _0);
			ZEPHIR_INIT_NVAR(&p);
			ZEPHIR_CONCAT_VSV(&p, &prefix, ".", &idx);
			if (Z_TYPE_P(&name) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_4$$4);
				zephir_create_array(&_4$$4, 6, 0);
				zephir_array_update_string(&_4$$4, SL("name"), &name, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_5$$4);
				zephir_array_fetch(&_5$$4, &types, &idx, PH_NOISY, "phalcon/http/request.zep", 927);
				zephir_array_update_string(&_4$$4, SL("type"), &_5$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_5$$4);
				zephir_array_fetch(&_5$$4, &tmp_names, &idx, PH_NOISY, "phalcon/http/request.zep", 928);
				zephir_array_update_string(&_4$$4, SL("tmp_name"), &_5$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_5$$4);
				zephir_array_fetch(&_5$$4, &sizes, &idx, PH_NOISY, "phalcon/http/request.zep", 929);
				zephir_array_update_string(&_4$$4, SL("size"), &_5$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_5$$4);
				zephir_array_fetch(&_5$$4, &errors, &idx, PH_NOISY, "phalcon/http/request.zep", 930);
				zephir_array_update_string(&_4$$4, SL("error"), &_5$$4, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_4$$4, SL("key"), &p, PH_COPY | PH_SEPARATE);
				zephir_array_append(&files, &_4$$4, PH_SEPARATE, "phalcon/http/request.zep", 932);
			}
			if (Z_TYPE_P(&name) == IS_ARRAY) {
				zephir_array_fetch(&_6$$5, &names, &idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 937);
				zephir_array_fetch(&_7$$5, &types, &idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 938);
				zephir_array_fetch(&_8$$5, &tmp_names, &idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 939);
				zephir_array_fetch(&_9$$5, &sizes, &idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 940);
				zephir_array_fetch(&_10$$5, &errors, &idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 941);
				ZEPHIR_CALL_METHOD(&parentFiles, this_ptr, "smoothfiles", &_11, 217, &_6$$5, &_7$$5, &_8$$5, &_9$$5, &_10$$5, &p);
				zephir_check_call_status();
				zephir_is_iterable(&parentFiles, 0, "phalcon/http/request.zep", 948);
				if (Z_TYPE_P(&parentFiles) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parentFiles), _12$$5)
					{
						ZEPHIR_INIT_NVAR(&file);
						ZVAL_COPY(&file, _12$$5);
						zephir_array_append(&files, &file, PH_SEPARATE, "phalcon/http/request.zep", 946);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &parentFiles, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_13$$5, &parentFiles, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_13$$5)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&file, &parentFiles, "current", NULL, 0);
						zephir_check_call_status();
							zephir_array_append(&files, &file, PH_SEPARATE, "phalcon/http/request.zep", 946);
						ZEPHIR_CALL_METHOD(NULL, &parentFiles, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&file);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &names, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &names, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&idx, &names, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&name, &names, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&p);
				ZEPHIR_CONCAT_VSV(&p, &prefix, ".", &idx);
				if (Z_TYPE_P(&name) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_14$$9);
					zephir_create_array(&_14$$9, 6, 0);
					zephir_array_update_string(&_14$$9, SL("name"), &name, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_15$$9);
					zephir_array_fetch(&_15$$9, &types, &idx, PH_NOISY, "phalcon/http/request.zep", 927);
					zephir_array_update_string(&_14$$9, SL("type"), &_15$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_15$$9);
					zephir_array_fetch(&_15$$9, &tmp_names, &idx, PH_NOISY, "phalcon/http/request.zep", 928);
					zephir_array_update_string(&_14$$9, SL("tmp_name"), &_15$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_15$$9);
					zephir_array_fetch(&_15$$9, &sizes, &idx, PH_NOISY, "phalcon/http/request.zep", 929);
					zephir_array_update_string(&_14$$9, SL("size"), &_15$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_15$$9);
					zephir_array_fetch(&_15$$9, &errors, &idx, PH_NOISY, "phalcon/http/request.zep", 930);
					zephir_array_update_string(&_14$$9, SL("error"), &_15$$9, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_14$$9, SL("key"), &p, PH_COPY | PH_SEPARATE);
					zephir_array_append(&files, &_14$$9, PH_SEPARATE, "phalcon/http/request.zep", 932);
				}
				if (Z_TYPE_P(&name) == IS_ARRAY) {
					zephir_array_fetch(&_16$$10, &names, &idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 937);
					zephir_array_fetch(&_17$$10, &types, &idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 938);
					zephir_array_fetch(&_18$$10, &tmp_names, &idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 939);
					zephir_array_fetch(&_19$$10, &sizes, &idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 940);
					zephir_array_fetch(&_20$$10, &errors, &idx, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 941);
					ZEPHIR_CALL_METHOD(&parentFiles, this_ptr, "smoothfiles", &_11, 217, &_16$$10, &_17$$10, &_18$$10, &_19$$10, &_20$$10, &p);
					zephir_check_call_status();
					zephir_is_iterable(&parentFiles, 0, "phalcon/http/request.zep", 948);
					if (Z_TYPE_P(&parentFiles) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parentFiles), _21$$10)
						{
							ZEPHIR_INIT_NVAR(&file);
							ZVAL_COPY(&file, _21$$10);
							zephir_array_append(&files, &file, PH_SEPARATE, "phalcon/http/request.zep", 946);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &parentFiles, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_22$$10, &parentFiles, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_22$$10)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&file, &parentFiles, "current", NULL, 0);
							zephir_check_call_status();
								zephir_array_append(&files, &file, PH_SEPARATE, "phalcon/http/request.zep", 946);
							ZEPHIR_CALL_METHOD(NULL, &parentFiles, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&file);
				}
			ZEPHIR_CALL_METHOD(NULL, &names, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_INIT_NVAR(&idx);
	RETURN_CCTOR(&files);

}

/**
 * Returns the available headers in the request
 *
 * <code>
 * $_SERVER = [
 *     "PHP_AUTH_USER" => "phalcon",
 *     "PHP_AUTH_PW"   => "secret",
 * ];
 *
 * $headers = $request->getHeaders();
 *
 * echo $headers["Authorization"]; // Basic cGhhbGNvbjpzZWNyZXQ=
 * </code>
 */
PHP_METHOD(Phalcon_Http_Request, getHeaders) {

	zend_string *_3;
	zend_ulong _2;
	zval headers, contentHeaders;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, _SERVER, name, value, authHeaders, *_0, _1, _4$$4, _5$$4, _6$$4, _7$$4, _8$$4, _9$$4, _11$$4, _12$$4, _13$$4, _14$$3, _15$$5, _16$$5, _17$$5, _18$$5, _19$$5, _20$$5, _21$$5, _22$$7, _23$$7, _24$$7, _25$$7, _26$$7, _27$$7, _28$$7, _29$$7, _30$$7, _31$$6, _32$$8, _33$$8, _34$$8, _35$$8, _36$$8, _37$$8, _38$$8, _39$$9;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&authHeaders);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_31$$6);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_34$$8);
	ZVAL_UNDEF(&_35$$8);
	ZVAL_UNDEF(&_36$$8);
	ZVAL_UNDEF(&_37$$8);
	ZVAL_UNDEF(&_38$$8);
	ZVAL_UNDEF(&_39$$9);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&contentHeaders);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_INIT_VAR(&headers);
	array_init(&headers);
	ZEPHIR_INIT_VAR(&contentHeaders);
	zephir_create_array(&contentHeaders, 3, 0);
	zephir_array_update_string(&contentHeaders, SL("CONTENT_TYPE"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&contentHeaders, SL("CONTENT_LENGTH"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&contentHeaders, SL("CONTENT_MD5"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_is_iterable(&_SERVER, 0, "phalcon/http/request.zep", 994);
	if (Z_TYPE_P(&_SERVER) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_SERVER), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&name, _3);
			} else {
				ZVAL_LONG(&name, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (zephir_start_with_str(&name, SL("HTTP_"))) {
				ZEPHIR_INIT_NVAR(&_4$$4);
				ZEPHIR_INIT_NVAR(&_5$$4);
				ZVAL_LONG(&_6$$4, 5);
				ZEPHIR_INIT_NVAR(&_7$$4);
				zephir_substr(&_7$$4, &name, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_INIT_NVAR(&_8$$4);
				ZVAL_STRING(&_8$$4, "_");
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZVAL_STRING(&_9$$4, " ");
				zephir_fast_str_replace(&_5$$4, &_8$$4, &_9$$4, &_7$$4);
				zephir_fast_strtolower(&_4$$4, &_5$$4);
				ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_10, 219, &_4$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_11$$4);
				ZEPHIR_INIT_NVAR(&_12$$4);
				ZVAL_STRING(&_12$$4, " ");
				ZEPHIR_INIT_NVAR(&_13$$4);
				ZVAL_STRING(&_13$$4, "-");
				zephir_fast_str_replace(&_11$$4, &_12$$4, &_13$$4, &name);
				ZEPHIR_CPY_WRT(&name, &_11$$4);
				zephir_array_update_zval(&headers, &name, &value, PH_COPY | PH_SEPARATE);
				continue;
			}
			ZEPHIR_INIT_NVAR(&_14$$3);
			zephir_fast_strtoupper(&_14$$3, &name);
			ZEPHIR_CPY_WRT(&name, &_14$$3);
			if (zephir_array_isset(&contentHeaders, &name)) {
				ZEPHIR_INIT_NVAR(&_15$$5);
				ZEPHIR_INIT_NVAR(&_16$$5);
				ZEPHIR_INIT_NVAR(&_17$$5);
				ZVAL_STRING(&_17$$5, "_");
				ZEPHIR_INIT_NVAR(&_18$$5);
				ZVAL_STRING(&_18$$5, " ");
				zephir_fast_str_replace(&_16$$5, &_17$$5, &_18$$5, &name);
				zephir_fast_strtolower(&_15$$5, &_16$$5);
				ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_10, 219, &_15$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_19$$5);
				ZEPHIR_INIT_NVAR(&_20$$5);
				ZVAL_STRING(&_20$$5, " ");
				ZEPHIR_INIT_NVAR(&_21$$5);
				ZVAL_STRING(&_21$$5, "-");
				zephir_fast_str_replace(&_19$$5, &_20$$5, &_21$$5, &name);
				ZEPHIR_CPY_WRT(&name, &_19$$5);
				zephir_array_update_zval(&headers, &name, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_SERVER, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &_SERVER, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &_SERVER, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_SERVER, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_start_with_str(&name, SL("HTTP_"))) {
					ZEPHIR_INIT_NVAR(&_22$$7);
					ZEPHIR_INIT_NVAR(&_23$$7);
					ZVAL_LONG(&_24$$7, 5);
					ZEPHIR_INIT_NVAR(&_25$$7);
					zephir_substr(&_25$$7, &name, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
					ZEPHIR_INIT_NVAR(&_26$$7);
					ZVAL_STRING(&_26$$7, "_");
					ZEPHIR_INIT_NVAR(&_27$$7);
					ZVAL_STRING(&_27$$7, " ");
					zephir_fast_str_replace(&_23$$7, &_26$$7, &_27$$7, &_25$$7);
					zephir_fast_strtolower(&_22$$7, &_23$$7);
					ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_10, 219, &_22$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_28$$7);
					ZEPHIR_INIT_NVAR(&_29$$7);
					ZVAL_STRING(&_29$$7, " ");
					ZEPHIR_INIT_NVAR(&_30$$7);
					ZVAL_STRING(&_30$$7, "-");
					zephir_fast_str_replace(&_28$$7, &_29$$7, &_30$$7, &name);
					ZEPHIR_CPY_WRT(&name, &_28$$7);
					zephir_array_update_zval(&headers, &name, &value, PH_COPY | PH_SEPARATE);
					continue;
				}
				ZEPHIR_INIT_NVAR(&_31$$6);
				zephir_fast_strtoupper(&_31$$6, &name);
				ZEPHIR_CPY_WRT(&name, &_31$$6);
				if (zephir_array_isset(&contentHeaders, &name)) {
					ZEPHIR_INIT_NVAR(&_32$$8);
					ZEPHIR_INIT_NVAR(&_33$$8);
					ZEPHIR_INIT_NVAR(&_34$$8);
					ZVAL_STRING(&_34$$8, "_");
					ZEPHIR_INIT_NVAR(&_35$$8);
					ZVAL_STRING(&_35$$8, " ");
					zephir_fast_str_replace(&_33$$8, &_34$$8, &_35$$8, &name);
					zephir_fast_strtolower(&_32$$8, &_33$$8);
					ZEPHIR_CALL_FUNCTION(&name, "ucwords", &_10, 219, &_32$$8);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_36$$8);
					ZEPHIR_INIT_NVAR(&_37$$8);
					ZVAL_STRING(&_37$$8, " ");
					ZEPHIR_INIT_NVAR(&_38$$8);
					ZVAL_STRING(&_38$$8, "-");
					zephir_fast_str_replace(&_36$$8, &_37$$8, &_38$$8, &name);
					ZEPHIR_CPY_WRT(&name, &_36$$8);
					zephir_array_update_zval(&headers, &name, &value, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &_SERVER, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_CALL_METHOD(&authHeaders, this_ptr, "resolveauthorizationheaders", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&authHeaders) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_39$$9);
		zephir_fast_array_merge(&_39$$9, &headers, &authHeaders);
		ZEPHIR_CPY_WRT(&headers, &_39$$9);
	}
	RETURN_CTOR(&headers);

}

/**
 * Resolve authorization headers.
 */
PHP_METHOD(Phalcon_Http_Request, resolveAuthorizationHeaders) {

	zval headers, _6$$5, _28$$19;
	zend_bool hasEventsManager = 0, _5, _9, _27, _15$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval _SERVER, resolved, eventsManager, dependencyInjector, exploded, digest, authHeader, _0, _1$$3, _2$$3, _3$$4, _4$$4, _7$$5, _8$$6, _10$$7, _11$$7, _12$$11, _13$$11, _14$$11, _16$$11, _17$$12, _18$$12, _19$$12, _20$$13, _21$$13, _22$$17, _23$$17, _24$$17, _25$$17, _26$$17, _29$$19, _30$$20;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&resolved);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&exploded);
	ZVAL_UNDEF(&digest);
	ZVAL_UNDEF(&authHeader);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_22$$17);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_29$$19);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_28$$19);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_INIT_VAR(&authHeader);
	ZVAL_NULL(&authHeader);
	ZEPHIR_INIT_VAR(&headers);
	array_init(&headers);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&dependencyInjector, &_0);
	if (Z_TYPE_P(&dependencyInjector) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "eventsManager");
		ZEPHIR_CALL_METHOD(&_1$$3, &dependencyInjector, "has", NULL, 0, &_2$$3);
		zephir_check_call_status();
		hasEventsManager = zephir_get_boolval(&_1$$3);
		if (hasEventsManager) {
			ZEPHIR_INIT_VAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "eventsManager");
			ZEPHIR_CALL_METHOD(&_3$$4, &dependencyInjector, "getshared", NULL, 0, &_4$$4);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&eventsManager, &_3$$4);
		}
	}
	_5 = hasEventsManager;
	if (_5) {
		_5 = Z_TYPE_P(&eventsManager) == IS_OBJECT;
	}
	if (_5) {
		ZEPHIR_INIT_VAR(&_6$$5);
		zephir_create_array(&_6$$5, 1, 0);
		zephir_array_update_string(&_6$$5, SL("server"), &_SERVER, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_7$$5);
		ZVAL_STRING(&_7$$5, "request:beforeAuthorizationResolve");
		ZEPHIR_CALL_METHOD(&resolved, &eventsManager, "fire", NULL, 0, &_7$$5, this_ptr, &_6$$5);
		zephir_check_call_status();
		if (Z_TYPE_P(&resolved) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_8$$6);
			zephir_fast_array_merge(&_8$$6, &headers, &resolved);
			ZEPHIR_CPY_WRT(&headers, &_8$$6);
		}
	}
	_9 = zephir_array_isset_string(&_SERVER, SL("PHP_AUTH_USER"));
	if (_9) {
		_9 = zephir_array_isset_string(&_SERVER, SL("PHP_AUTH_PW"));
	}
	if (_9) {
		zephir_array_fetch_string(&_10$$7, &_SERVER, SL("PHP_AUTH_USER"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1035);
		zephir_array_update_string(&headers, SL("Php-Auth-User"), &_10$$7, PH_COPY | PH_SEPARATE);
		zephir_array_fetch_string(&_11$$7, &_SERVER, SL("PHP_AUTH_PW"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1036);
		zephir_array_update_string(&headers, SL("Php-Auth-Pw"), &_11$$7, PH_COPY | PH_SEPARATE);
	} else {
		if (zephir_array_isset_string(&_SERVER, SL("HTTP_AUTHORIZATION"))) {
			ZEPHIR_OBS_NVAR(&authHeader);
			zephir_array_fetch_string(&authHeader, &_SERVER, SL("HTTP_AUTHORIZATION"), PH_NOISY, "phalcon/http/request.zep", 1039);
		} else if (zephir_array_isset_string(&_SERVER, SL("REDIRECT_HTTP_AUTHORIZATION"))) {
			ZEPHIR_OBS_NVAR(&authHeader);
			zephir_array_fetch_string(&authHeader, &_SERVER, SL("REDIRECT_HTTP_AUTHORIZATION"), PH_NOISY, "phalcon/http/request.zep", 1041);
		}
		if (zephir_is_true(&authHeader)) {
			ZEPHIR_INIT_VAR(&_12$$11);
			ZVAL_STRING(&_12$$11, "basic ");
			ZEPHIR_CALL_FUNCTION(&_13$$11, "stripos", NULL, 208, &authHeader, &_12$$11);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_12$$11);
			ZVAL_STRING(&_12$$11, "digest ");
			ZEPHIR_CALL_FUNCTION(&_14$$11, "stripos", NULL, 208, &authHeader, &_12$$11);
			zephir_check_call_status();
			_15$$11 = ZEPHIR_IS_LONG_IDENTICAL(&_14$$11, 0);
			if (_15$$11) {
				ZEPHIR_OBS_VAR(&digest);
				_15$$11 = !(zephir_array_isset_string_fetch(&digest, &_SERVER, SL("PHP_AUTH_DIGEST"), 0));
			}
			ZEPHIR_INIT_NVAR(&_12$$11);
			ZVAL_STRING(&_12$$11, "bearer ");
			ZEPHIR_CALL_FUNCTION(&_16$$11, "stripos", NULL, 208, &authHeader, &_12$$11);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_13$$11, 0)) {
				ZVAL_LONG(&_17$$12, 6);
				ZEPHIR_INIT_VAR(&_18$$12);
				zephir_substr(&_18$$12, &authHeader, 6 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_CALL_FUNCTION(&_19$$12, "base64_decode", NULL, 122, &_18$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&exploded);
				zephir_fast_explode_str(&exploded, SL(":"), &_19$$12, 2 );
				if (zephir_fast_count_int(&exploded) == 2) {
					zephir_array_fetch_long(&_20$$13, &exploded, 0, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1048);
					zephir_array_update_string(&headers, SL("Php-Auth-User"), &_20$$13, PH_COPY | PH_SEPARATE);
					zephir_array_fetch_long(&_21$$13, &exploded, 1, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1049);
					zephir_array_update_string(&headers, SL("Php-Auth-Pw"), &_21$$13, PH_COPY | PH_SEPARATE);
				}
			} else if (_15$$11) {
				zephir_array_update_string(&headers, SL("Php-Auth-Digest"), &authHeader, PH_COPY | PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_16$$11, 0)) {
				zephir_array_update_string(&headers, SL("Authorization"), &authHeader, PH_COPY | PH_SEPARATE);
			}
		}
	}
	if (!(zephir_array_isset_string(&headers, SL("Authorization")))) {
		ZEPHIR_OBS_NVAR(&digest);
		if (zephir_array_isset_string(&headers, SL("Php-Auth-User"))) {
			zephir_array_fetch_string(&_22$$17, &headers, SL("Php-Auth-User"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1061);
			zephir_array_fetch_string(&_23$$17, &headers, SL("Php-Auth-Pw"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1061);
			ZEPHIR_INIT_VAR(&_24$$17);
			ZEPHIR_CONCAT_VSV(&_24$$17, &_22$$17, ":", &_23$$17);
			ZEPHIR_CALL_FUNCTION(&_25$$17, "base64_encode", NULL, 121, &_24$$17);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_26$$17);
			ZEPHIR_CONCAT_SV(&_26$$17, "Basic ", &_25$$17);
			zephir_array_update_string(&headers, SL("Authorization"), &_26$$17, PH_COPY | PH_SEPARATE);
		} else if (zephir_array_isset_string_fetch(&digest, &headers, SL("Php-Auth-Digest"), 0)) {
			zephir_array_update_string(&headers, SL("Authorization"), &digest, PH_COPY | PH_SEPARATE);
		}
	}
	_27 = hasEventsManager;
	if (_27) {
		_27 = Z_TYPE_P(&eventsManager) == IS_OBJECT;
	}
	if (_27) {
		ZEPHIR_INIT_VAR(&_28$$19);
		zephir_create_array(&_28$$19, 2, 0);
		zephir_array_update_string(&_28$$19, SL("headers"), &headers, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_28$$19, SL("server"), &_SERVER, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_29$$19);
		ZVAL_STRING(&_29$$19, "request:afterAuthorizationResolve");
		ZEPHIR_CALL_METHOD(&resolved, &eventsManager, "fire", NULL, 0, &_29$$19, this_ptr, &_28$$19);
		zephir_check_call_status();
		if (Z_TYPE_P(&resolved) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_30$$20);
			zephir_fast_array_merge(&_30$$20, &headers, &resolved);
			ZEPHIR_CPY_WRT(&headers, &_30$$20);
		}
	}
	RETURN_CTOR(&headers);

}

/**
 * Gets web page that refers active request. ie: http://www.google.com
 */
PHP_METHOD(Phalcon_Http_Request, getHTTPReferer) {

	zval _SERVER, httpReferer;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&httpReferer);

	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (zephir_array_isset_string_fetch(&httpReferer, &_SERVER, SL("HTTP_REFERER"), 1)) {
		RETURN_CTORW(&httpReferer);
	}
	RETURN_STRING("");

}

/**
 * Process a request header and return the one with best quality
 */
PHP_METHOD(Phalcon_Http_Request, _getBestQuality) {

	double quality = 0, acceptQuality = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0;
	zval name;
	zval *qualityParts_param = NULL, *name_param = NULL, selectedName, accept, *_0, _1, _2$$4, _3$$5, _4$$8, _5$$9;
	zval qualityParts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&qualityParts);
	ZVAL_UNDEF(&selectedName);
	ZVAL_UNDEF(&accept);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &qualityParts_param, &name_param);

	zephir_get_arrval(&qualityParts, qualityParts_param);
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


	i = 0;
	quality = 0.0;
	ZEPHIR_INIT_VAR(&selectedName);
	ZVAL_STRING(&selectedName, "");
	zephir_is_iterable(&qualityParts, 0, "phalcon/http/request.zep", 1121);
	if (Z_TYPE_P(&qualityParts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&qualityParts), _0)
		{
			ZEPHIR_INIT_NVAR(&accept);
			ZVAL_COPY(&accept, _0);
			if (i == 0) {
				ZEPHIR_OBS_NVAR(&_2$$4);
				zephir_array_fetch_string(&_2$$4, &accept, SL("quality"), PH_NOISY, "phalcon/http/request.zep", 1110);
				quality = zephir_get_doubleval(&_2$$4);
				ZEPHIR_OBS_NVAR(&selectedName);
				zephir_array_fetch(&selectedName, &accept, &name, PH_NOISY, "phalcon/http/request.zep", 1111);
			} else {
				ZEPHIR_OBS_NVAR(&_3$$5);
				zephir_array_fetch_string(&_3$$5, &accept, SL("quality"), PH_NOISY, "phalcon/http/request.zep", 1113);
				acceptQuality = zephir_get_doubleval(&_3$$5);
				if (acceptQuality > quality) {
					quality = acceptQuality;
					ZEPHIR_OBS_NVAR(&selectedName);
					zephir_array_fetch(&selectedName, &accept, &name, PH_NOISY, "phalcon/http/request.zep", 1116);
				}
			}
			i++;
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &qualityParts, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &qualityParts, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&accept, &qualityParts, "current", NULL, 0);
			zephir_check_call_status();
				if (i == 0) {
					ZEPHIR_OBS_NVAR(&_4$$8);
					zephir_array_fetch_string(&_4$$8, &accept, SL("quality"), PH_NOISY, "phalcon/http/request.zep", 1110);
					quality = zephir_get_doubleval(&_4$$8);
					ZEPHIR_OBS_NVAR(&selectedName);
					zephir_array_fetch(&selectedName, &accept, &name, PH_NOISY, "phalcon/http/request.zep", 1111);
				} else {
					ZEPHIR_OBS_NVAR(&_5$$9);
					zephir_array_fetch_string(&_5$$9, &accept, SL("quality"), PH_NOISY, "phalcon/http/request.zep", 1113);
					acceptQuality = zephir_get_doubleval(&_5$$9);
					if (acceptQuality > quality) {
						quality = acceptQuality;
						ZEPHIR_OBS_NVAR(&selectedName);
						zephir_array_fetch(&selectedName, &accept, &name, PH_NOISY, "phalcon/http/request.zep", 1116);
					}
				}
				i++;
			ZEPHIR_CALL_METHOD(NULL, &qualityParts, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&accept);
	RETURN_CCTOR(&selectedName);

}

/**
 * Gets content type which request has been made
 */
PHP_METHOD(Phalcon_Http_Request, getContentType) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval _SERVER, contentType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&contentType);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_OBS_VAR(&contentType);
	if (zephir_array_isset_string_fetch(&contentType, &_SERVER, SL("CONTENT_TYPE"), 0)) {
		RETURN_CCTOR(&contentType);
	} else {
		ZEPHIR_OBS_NVAR(&contentType);
		if (zephir_array_isset_string_fetch(&contentType, &_SERVER, SL("HTTP_CONTENT_TYPE"), 0)) {
			RETURN_CCTOR(&contentType);
		}
	}
	RETURN_MM_NULL();

}

/**
 * Gets an array with mime/types and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT"]
 */
PHP_METHOD(Phalcon_Http_Request, getAcceptableContent) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_ACCEPT");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "accept");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getqualityheader", NULL, 220, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets best mime/type accepted by the browser/client from _SERVER["HTTP_ACCEPT"]
 */
PHP_METHOD(Phalcon_Http_Request, getBestAccept) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getacceptablecontent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "accept");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getbestquality", NULL, 221, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets a charsets array and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT_CHARSET"]
 */
PHP_METHOD(Phalcon_Http_Request, getClientCharsets) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_ACCEPT_CHARSET");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "charset");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getqualityheader", NULL, 220, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets best charset accepted by the browser/client from _SERVER["HTTP_ACCEPT_CHARSET"]
 */
PHP_METHOD(Phalcon_Http_Request, getBestCharset) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getclientcharsets", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "charset");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getbestquality", NULL, 221, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets languages array and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT_LANGUAGE"]
 */
PHP_METHOD(Phalcon_Http_Request, getLanguages) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_ACCEPT_LANGUAGE");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "language");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getqualityheader", NULL, 220, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets best language accepted by the browser/client from _SERVER["HTTP_ACCEPT_LANGUAGE"]
 */
PHP_METHOD(Phalcon_Http_Request, getBestLanguage) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getlanguages", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "language");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getbestquality", NULL, 221, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets auth info accepted by the browser/client from $_SERVER["PHP_AUTH_USER"]
 */
PHP_METHOD(Phalcon_Http_Request, getBasicAuth) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval _SERVER, auth, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&auth);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	_0 = zephir_array_isset_string(&_SERVER, SL("PHP_AUTH_USER"));
	if (_0) {
		_0 = zephir_array_isset_string(&_SERVER, SL("PHP_AUTH_PW"));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&auth);
		array_init(&auth);
		zephir_array_fetch_string(&_1$$3, &_SERVER, SL("PHP_AUTH_USER"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1202);
		zephir_array_update_string(&auth, SL("username"), &_1$$3, PH_COPY | PH_SEPARATE);
		zephir_array_fetch_string(&_2$$3, &_SERVER, SL("PHP_AUTH_PW"), PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1203);
		zephir_array_update_string(&auth, SL("password"), &_2$$3, PH_COPY | PH_SEPARATE);
		RETURN_CCTOR(&auth);
	}
	RETURN_MM_NULL();

}

/**
 * Gets auth info accepted by the browser/client from $_SERVER["PHP_AUTH_DIGEST"]
 */
PHP_METHOD(Phalcon_Http_Request, getDigestAuth) {

	zval auth;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _SERVER, digest, matches, match, _0$$3, _1$$3, _2$$3, *_3$$5, _4$$5, _5$$6, _6$$6, _7$$7, _8$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&digest);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&match);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&auth);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_INIT_VAR(&auth);
	array_init(&auth);
	ZEPHIR_OBS_VAR(&digest);
	if (zephir_array_isset_string_fetch(&digest, &_SERVER, SL("PHP_AUTH_DIGEST"), 0)) {
		ZEPHIR_INIT_VAR(&matches);
		array_init(&matches);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "#(\\w+)=(['\"]?)([^'\" ,]+)\\2#");
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "#(\\w+)=(['\"]?)([^'\" ,]+)\\2#");
		zephir_preg_match(&_1$$3, &_2$$3, &digest, &matches, 1, 2 , 0 );
		if (!(zephir_is_true(&_1$$3))) {
			RETURN_CTOR(&auth);
		}
		if (Z_TYPE_P(&matches) == IS_ARRAY) {
			zephir_is_iterable(&matches, 0, "phalcon/http/request.zep", 1228);
			if (Z_TYPE_P(&matches) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&matches), _3$$5)
				{
					ZEPHIR_INIT_NVAR(&match);
					ZVAL_COPY(&match, _3$$5);
					zephir_array_fetch_long(&_5$$6, &match, 3, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1226);
					ZEPHIR_OBS_NVAR(&_6$$6);
					zephir_array_fetch_long(&_6$$6, &match, 1, PH_NOISY, "phalcon/http/request.zep", 1226);
					zephir_array_update_zval(&auth, &_6$$6, &_5$$6, PH_COPY | PH_SEPARATE);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &matches, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_4$$5, &matches, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_4$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&match, &matches, "current", NULL, 0);
					zephir_check_call_status();
						zephir_array_fetch_long(&_7$$7, &match, 3, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1226);
						ZEPHIR_OBS_NVAR(&_8$$7);
						zephir_array_fetch_long(&_8$$7, &match, 1, PH_NOISY, "phalcon/http/request.zep", 1226);
						zephir_array_update_zval(&auth, &_8$$7, &_7$$7, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &matches, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&match);
		}
	}
	RETURN_CTOR(&auth);

}

/**
 * Process a request header and return an array of values with their qualities
 */
PHP_METHOD(Phalcon_Http_Request, _getQualityHeader) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serverIndex_param = NULL, *name_param = NULL, returnedParts, part, headerParts, headerPart, split, _0, _1, _2, _3, _4, *_5, _6, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3, *_12$$3, _13$$3, _14$$4, _15$$4, _16$$5, _17$$6, _18$$6, _19$$7, _20$$7, _21$$8, _22$$9, _23$$9, _24$$10, _25$$11, _26$$11, _27$$12, _28$$12, _29$$13, _30$$14, _31$$14, _32$$14, _33$$14, _34$$14, *_35$$14, _36$$14, _37$$15, _38$$15, _39$$16, _40$$17, _41$$17, _42$$18, _43$$18, _44$$19, _45$$20, _46$$20, _47$$21, _48$$22, _49$$22, _50$$23, _51$$23, _52$$24;
	zval serverIndex, name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serverIndex);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&returnedParts);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&headerParts);
	ZVAL_UNDEF(&headerPart);
	ZVAL_UNDEF(&split);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_30$$14);
	ZVAL_UNDEF(&_31$$14);
	ZVAL_UNDEF(&_32$$14);
	ZVAL_UNDEF(&_33$$14);
	ZVAL_UNDEF(&_34$$14);
	ZVAL_UNDEF(&_36$$14);
	ZVAL_UNDEF(&_37$$15);
	ZVAL_UNDEF(&_38$$15);
	ZVAL_UNDEF(&_39$$16);
	ZVAL_UNDEF(&_40$$17);
	ZVAL_UNDEF(&_41$$17);
	ZVAL_UNDEF(&_42$$18);
	ZVAL_UNDEF(&_43$$18);
	ZVAL_UNDEF(&_44$$19);
	ZVAL_UNDEF(&_45$$20);
	ZVAL_UNDEF(&_46$$20);
	ZVAL_UNDEF(&_47$$21);
	ZVAL_UNDEF(&_48$$22);
	ZVAL_UNDEF(&_49$$22);
	ZVAL_UNDEF(&_50$$23);
	ZVAL_UNDEF(&_51$$23);
	ZVAL_UNDEF(&_52$$24);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &serverIndex_param, &name_param);

	if (UNEXPECTED(Z_TYPE_P(serverIndex_param) != IS_STRING && Z_TYPE_P(serverIndex_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serverIndex' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(serverIndex_param) == IS_STRING)) {
		zephir_get_strval(&serverIndex, serverIndex_param);
	} else {
		ZEPHIR_INIT_VAR(&serverIndex);
		ZVAL_EMPTY_STRING(&serverIndex);
	}
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


	ZEPHIR_INIT_VAR(&returnedParts);
	array_init(&returnedParts);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getserver", NULL, 0, &serverIndex);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/,\\s*/");
	ZVAL_LONG(&_2, -1);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&_4, "preg_split", NULL, 222, &_1, &_0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_4, 0, "phalcon/http/request.zep", 1262);
	if (Z_TYPE_P(&_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4), _5)
		{
			ZEPHIR_INIT_NVAR(&part);
			ZVAL_COPY(&part, _5);
			ZEPHIR_INIT_NVAR(&headerParts);
			array_init(&headerParts);
			ZEPHIR_INIT_NVAR(&_7$$3);
			zephir_fast_trim(&_7$$3, &part, NULL , ZEPHIR_TRIM_BOTH);
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZVAL_STRING(&_8$$3, "/\\s*;\\s*/");
			ZVAL_LONG(&_9$$3, -1);
			ZVAL_LONG(&_10$$3, 1);
			ZEPHIR_CALL_FUNCTION(&_11$$3, "preg_split", NULL, 222, &_8$$3, &_7$$3, &_9$$3, &_10$$3);
			zephir_check_call_status();
			zephir_is_iterable(&_11$$3, 0, "phalcon/http/request.zep", 1259);
			if (Z_TYPE_P(&_11$$3) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_11$$3), _12$$3)
				{
					ZEPHIR_INIT_NVAR(&headerPart);
					ZVAL_COPY(&headerPart, _12$$3);
					ZEPHIR_INIT_NVAR(&_14$$4);
					ZVAL_STRING(&_14$$4, "=");
					ZEPHIR_INIT_NVAR(&_15$$4);
					zephir_fast_strpos(&_15$$4, &headerPart, &_14$$4, 0 );
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&_15$$4)) {
						ZEPHIR_INIT_NVAR(&split);
						zephir_fast_explode_str(&split, SL("="), &headerPart, 2 );
						zephir_array_fetch_long(&_16$$5, &split, 0, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1248);
						if (ZEPHIR_IS_STRING_IDENTICAL(&_16$$5, "q")) {
							ZEPHIR_OBS_NVAR(&_17$$6);
							zephir_array_fetch_long(&_17$$6, &split, 1, PH_NOISY, "phalcon/http/request.zep", 1249);
							ZEPHIR_INIT_NVAR(&_18$$6);
							ZVAL_DOUBLE(&_18$$6, zephir_get_doubleval(&_17$$6));
							zephir_array_update_string(&headerParts, SL("quality"), &_18$$6, PH_COPY | PH_SEPARATE);
						} else {
							zephir_array_fetch_long(&_19$$7, &split, 1, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1251);
							ZEPHIR_OBS_NVAR(&_20$$7);
							zephir_array_fetch_long(&_20$$7, &split, 0, PH_NOISY, "phalcon/http/request.zep", 1251);
							zephir_array_update_zval(&headerParts, &_20$$7, &_19$$7, PH_COPY | PH_SEPARATE);
						}
					} else {
						zephir_array_update_zval(&headerParts, &name, &headerPart, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_21$$8);
						ZVAL_DOUBLE(&_21$$8, 1.0);
						zephir_array_update_string(&headerParts, SL("quality"), &_21$$8, PH_COPY | PH_SEPARATE);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_11$$3, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_13$$3, &_11$$3, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_13$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&headerPart, &_11$$3, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_22$$9);
						ZVAL_STRING(&_22$$9, "=");
						ZEPHIR_INIT_NVAR(&_23$$9);
						zephir_fast_strpos(&_23$$9, &headerPart, &_22$$9, 0 );
						if (!ZEPHIR_IS_FALSE_IDENTICAL(&_23$$9)) {
							ZEPHIR_INIT_NVAR(&split);
							zephir_fast_explode_str(&split, SL("="), &headerPart, 2 );
							zephir_array_fetch_long(&_24$$10, &split, 0, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1248);
							if (ZEPHIR_IS_STRING_IDENTICAL(&_24$$10, "q")) {
								ZEPHIR_OBS_NVAR(&_25$$11);
								zephir_array_fetch_long(&_25$$11, &split, 1, PH_NOISY, "phalcon/http/request.zep", 1249);
								ZEPHIR_INIT_NVAR(&_26$$11);
								ZVAL_DOUBLE(&_26$$11, zephir_get_doubleval(&_25$$11));
								zephir_array_update_string(&headerParts, SL("quality"), &_26$$11, PH_COPY | PH_SEPARATE);
							} else {
								zephir_array_fetch_long(&_27$$12, &split, 1, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1251);
								ZEPHIR_OBS_NVAR(&_28$$12);
								zephir_array_fetch_long(&_28$$12, &split, 0, PH_NOISY, "phalcon/http/request.zep", 1251);
								zephir_array_update_zval(&headerParts, &_28$$12, &_27$$12, PH_COPY | PH_SEPARATE);
							}
						} else {
							zephir_array_update_zval(&headerParts, &name, &headerPart, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_29$$13);
							ZVAL_DOUBLE(&_29$$13, 1.0);
							zephir_array_update_string(&headerParts, SL("quality"), &_29$$13, PH_COPY | PH_SEPARATE);
						}
					ZEPHIR_CALL_METHOD(NULL, &_11$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&headerPart);
			zephir_array_append(&returnedParts, &headerParts, PH_SEPARATE, "phalcon/http/request.zep", 1259);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_4, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &_4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&part, &_4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&headerParts);
				array_init(&headerParts);
				ZEPHIR_INIT_NVAR(&_30$$14);
				zephir_fast_trim(&_30$$14, &part, NULL , ZEPHIR_TRIM_BOTH);
				ZEPHIR_INIT_NVAR(&_31$$14);
				ZVAL_STRING(&_31$$14, "/\\s*;\\s*/");
				ZVAL_LONG(&_32$$14, -1);
				ZVAL_LONG(&_33$$14, 1);
				ZEPHIR_CALL_FUNCTION(&_34$$14, "preg_split", NULL, 222, &_31$$14, &_30$$14, &_32$$14, &_33$$14);
				zephir_check_call_status();
				zephir_is_iterable(&_34$$14, 0, "phalcon/http/request.zep", 1259);
				if (Z_TYPE_P(&_34$$14) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_34$$14), _35$$14)
					{
						ZEPHIR_INIT_NVAR(&headerPart);
						ZVAL_COPY(&headerPart, _35$$14);
						ZEPHIR_INIT_NVAR(&_37$$15);
						ZVAL_STRING(&_37$$15, "=");
						ZEPHIR_INIT_NVAR(&_38$$15);
						zephir_fast_strpos(&_38$$15, &headerPart, &_37$$15, 0 );
						if (!ZEPHIR_IS_FALSE_IDENTICAL(&_38$$15)) {
							ZEPHIR_INIT_NVAR(&split);
							zephir_fast_explode_str(&split, SL("="), &headerPart, 2 );
							zephir_array_fetch_long(&_39$$16, &split, 0, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1248);
							if (ZEPHIR_IS_STRING_IDENTICAL(&_39$$16, "q")) {
								ZEPHIR_OBS_NVAR(&_40$$17);
								zephir_array_fetch_long(&_40$$17, &split, 1, PH_NOISY, "phalcon/http/request.zep", 1249);
								ZEPHIR_INIT_NVAR(&_41$$17);
								ZVAL_DOUBLE(&_41$$17, zephir_get_doubleval(&_40$$17));
								zephir_array_update_string(&headerParts, SL("quality"), &_41$$17, PH_COPY | PH_SEPARATE);
							} else {
								zephir_array_fetch_long(&_42$$18, &split, 1, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1251);
								ZEPHIR_OBS_NVAR(&_43$$18);
								zephir_array_fetch_long(&_43$$18, &split, 0, PH_NOISY, "phalcon/http/request.zep", 1251);
								zephir_array_update_zval(&headerParts, &_43$$18, &_42$$18, PH_COPY | PH_SEPARATE);
							}
						} else {
							zephir_array_update_zval(&headerParts, &name, &headerPart, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_44$$19);
							ZVAL_DOUBLE(&_44$$19, 1.0);
							zephir_array_update_string(&headerParts, SL("quality"), &_44$$19, PH_COPY | PH_SEPARATE);
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_34$$14, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_36$$14, &_34$$14, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_36$$14)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&headerPart, &_34$$14, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_45$$20);
							ZVAL_STRING(&_45$$20, "=");
							ZEPHIR_INIT_NVAR(&_46$$20);
							zephir_fast_strpos(&_46$$20, &headerPart, &_45$$20, 0 );
							if (!ZEPHIR_IS_FALSE_IDENTICAL(&_46$$20)) {
								ZEPHIR_INIT_NVAR(&split);
								zephir_fast_explode_str(&split, SL("="), &headerPart, 2 );
								zephir_array_fetch_long(&_47$$21, &split, 0, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1248);
								if (ZEPHIR_IS_STRING_IDENTICAL(&_47$$21, "q")) {
									ZEPHIR_OBS_NVAR(&_48$$22);
									zephir_array_fetch_long(&_48$$22, &split, 1, PH_NOISY, "phalcon/http/request.zep", 1249);
									ZEPHIR_INIT_NVAR(&_49$$22);
									ZVAL_DOUBLE(&_49$$22, zephir_get_doubleval(&_48$$22));
									zephir_array_update_string(&headerParts, SL("quality"), &_49$$22, PH_COPY | PH_SEPARATE);
								} else {
									zephir_array_fetch_long(&_50$$23, &split, 1, PH_NOISY | PH_READONLY, "phalcon/http/request.zep", 1251);
									ZEPHIR_OBS_NVAR(&_51$$23);
									zephir_array_fetch_long(&_51$$23, &split, 0, PH_NOISY, "phalcon/http/request.zep", 1251);
									zephir_array_update_zval(&headerParts, &_51$$23, &_50$$23, PH_COPY | PH_SEPARATE);
								}
							} else {
								zephir_array_update_zval(&headerParts, &name, &headerPart, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_52$$24);
								ZVAL_DOUBLE(&_52$$24, 1.0);
								zephir_array_update_string(&headerParts, SL("quality"), &_52$$24, PH_COPY | PH_SEPARATE);
							}
						ZEPHIR_CALL_METHOD(NULL, &_34$$14, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&headerPart);
				zephir_array_append(&returnedParts, &headerParts, PH_SEPARATE, "phalcon/http/request.zep", 1259);
			ZEPHIR_CALL_METHOD(NULL, &_4, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&part);
	RETURN_CCTOR(&returnedParts);

}

