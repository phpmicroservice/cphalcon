
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
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Phalcon\Mvc\Router
 *
 * Phalcon\Mvc\Router is the standard framework router. Routing is the
 * process of taking a URI endpoint (that part of the URI which comes after the base URL) and
 * decomposing it into parameters to determine which module, controller, and
 * action of that controller should receive the request
 *
 * <code>
 * use Phalcon\Mvc\Router;
 *
 * $router = new Router();
 *
 * $router->add(
 *     "/documentation/{chapter}/{name}\.{type:[a-z]+}",
 *     [
 *         "controller" => "documentation",
 *         "action"     => "show",
 *     ]
 * );
 *
 * $router->handle();
 *
 * echo $router->getControllerName();
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc, Router, phalcon, mvc_router, phalcon_mvc_router_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_uriSource"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_namespace"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_module"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_controller"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_action"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_params"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_routes"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_matchedRoute"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_matches"), ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalcon_mvc_router_ce, SL("_wasMatched"), 0, ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultNamespace"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultModule"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultController"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultAction"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultParams"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_removeExtraSlashes"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_notFoundPaths"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_keyRouteNames"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_ce, SL("_keyRouteIds"), ZEND_ACC_PROTECTED);

	phalcon_mvc_router_ce->create_object = zephir_init_properties_Phalcon_Mvc_Router;
	zephir_declare_class_constant_long(phalcon_mvc_router_ce, SL("URI_SOURCE_GET_URL"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_router_ce, SL("URI_SOURCE_SERVER_REQUEST_URI"), 1);

	zephir_declare_class_constant_long(phalcon_mvc_router_ce, SL("POSITION_FIRST"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_router_ce, SL("POSITION_LAST"), 1);

	zend_class_implements(phalcon_mvc_router_ce, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_mvc_router_ce, 1, phalcon_mvc_routerinterface_ce);
	zend_class_implements(phalcon_mvc_router_ce, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Mvc_Router, getKeyRouteNames) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_keyRouteNames");

}

PHP_METHOD(Phalcon_Mvc_Router, setKeyRouteNames) {

	zval *keyRouteNames, keyRouteNames_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyRouteNames_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &keyRouteNames);



	zephir_update_property_zval(this_ptr, SL("_keyRouteNames"), keyRouteNames);
	RETURN_THISW();

}

PHP_METHOD(Phalcon_Mvc_Router, getKeyRouteIds) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_keyRouteIds");

}

PHP_METHOD(Phalcon_Mvc_Router, setKeyRouteIds) {

	zval *keyRouteIds, keyRouteIds_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyRouteIds_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &keyRouteIds);



	zephir_update_property_zval(this_ptr, SL("_keyRouteIds"), keyRouteIds);
	RETURN_THISW();

}

/**
 * Phalcon\Mvc\Router constructor
 */
PHP_METHOD(Phalcon_Mvc_Router, __construct) {

	zval routes, _1$$3, _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *defaultRoutes_param = NULL, _0$$3, _2$$3, _4$$3;
	zend_bool defaultRoutes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&routes);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &defaultRoutes_param);

	if (!defaultRoutes_param) {
		defaultRoutes = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(defaultRoutes_param) != IS_TRUE && Z_TYPE_P(defaultRoutes_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'defaultRoutes' must be of the type bool"));
		RETURN_MM_NULL();
	}
	defaultRoutes = (Z_TYPE_P(defaultRoutes_param) == IS_TRUE);
	}


	ZEPHIR_INIT_VAR(&routes);
	array_init(&routes);
	if (defaultRoutes) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_router_route_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 1, 0);
		add_assoc_long_ex(&_1$$3, SL("controller"), 1);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "#^/([\\w0-9\\_\\-]+)[/]{0,1}$#u");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 74, &_2$$3, &_1$$3);
		zephir_check_call_status();
		zephir_array_append(&routes, &_0$$3, PH_SEPARATE, "phalcon/mvc/router.zep", 124);
		ZEPHIR_INIT_NVAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_mvc_router_route_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 3, 0);
		add_assoc_long_ex(&_3$$3, SL("controller"), 1);
		add_assoc_long_ex(&_3$$3, SL("action"), 2);
		add_assoc_long_ex(&_3$$3, SL("params"), 3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "#^/([\\w0-9\\_\\-]+)/([\\w0-9\\.\\_]+)(/.*)*$#u");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 74, &_4$$3, &_3$$3);
		zephir_check_call_status();
		zephir_array_append(&routes, &_2$$3, PH_SEPARATE, "phalcon/mvc/router.zep", 130);
	}
	zephir_update_property_zval(this_ptr, SL("_routes"), &routes);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Mvc_Router, setDI) {

	zval *dependencyInjector, dependencyInjector_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &dependencyInjector);



	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Mvc_Router, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Mvc_Router, setEventsManager) {

	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);



	zephir_update_property_zval(this_ptr, SL("_eventsManager"), eventsManager);

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Mvc_Router, getEventsManager) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_eventsManager");

}

/**
 * Get rewrite info. This info is read from $_GET["_url"]. This returns '/' if the rewrite information cannot be read
 */
PHP_METHOD(Phalcon_Mvc_Router, getRewriteUri) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval _GET, _SERVER, url, urlParts, realUri, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&urlParts);
	ZVAL_UNDEF(&realUri);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_get_global(&_GET, SL("_GET"));

	zephir_read_property(&_0, this_ptr, SL("_uriSource"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_OBS_VAR(&url);
		if (zephir_array_isset_string_fetch(&url, &_GET, SL("_url"), 0)) {
			if (!(ZEPHIR_IS_EMPTY(&url))) {
				RETURN_CCTOR(&url);
			}
		}
	} else {
		ZEPHIR_OBS_NVAR(&url);
		if (zephir_array_isset_string_fetch(&url, &_SERVER, SL("REQUEST_URI"), 0)) {
			ZEPHIR_INIT_VAR(&urlParts);
			zephir_fast_explode_str(&urlParts, SL("?"), &url, LONG_MAX);
			zephir_array_fetch_long(&realUri, &urlParts, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/router.zep", 190);
			if (!(ZEPHIR_IS_EMPTY(&realUri))) {
				RETURN_CTOR(&realUri);
			}
		}
	}
	RETURN_MM_STRING("/");

}

/**
 * Sets the URI source. One of the URI_SOURCE_* constants
 *
 * <code>
 * $router->setUriSource(
 *     Router::URI_SOURCE_SERVER_REQUEST_URI
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Router, setUriSource) {

	zval *uriSource, uriSource_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uriSource_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &uriSource);



	zephir_update_property_zval(this_ptr, SL("_uriSource"), uriSource);
	RETURN_THISW();

}

/**
 * Set whether router must remove the extra slashes in the handled routes
 */
PHP_METHOD(Phalcon_Mvc_Router, removeExtraSlashes) {

	zval *remove_param = NULL, __$true, __$false;
	zend_bool remove;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(1, 0, &remove_param);

	if (UNEXPECTED(Z_TYPE_P(remove_param) != IS_TRUE && Z_TYPE_P(remove_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'remove' must be of the type bool"));
		RETURN_NULL();
	}
	remove = (Z_TYPE_P(remove_param) == IS_TRUE);


	if (remove) {
		zephir_update_property_zval(this_ptr, SL("_removeExtraSlashes"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_removeExtraSlashes"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets the name of the default namespace
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultNamespace) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *namespaceName_param = NULL;
	zval namespaceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaceName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaceName_param);

	if (UNEXPECTED(Z_TYPE_P(namespaceName_param) != IS_STRING && Z_TYPE_P(namespaceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'namespaceName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(namespaceName_param) == IS_STRING)) {
		zephir_get_strval(&namespaceName, namespaceName_param);
	} else {
		ZEPHIR_INIT_VAR(&namespaceName);
		ZVAL_EMPTY_STRING(&namespaceName);
	}


	zephir_update_property_zval(this_ptr, SL("_defaultNamespace"), &namespaceName);
	RETURN_THIS();

}

/**
 * Sets the name of the default module
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultModule) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *moduleName_param = NULL;
	zval moduleName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

	if (UNEXPECTED(Z_TYPE_P(moduleName_param) != IS_STRING && Z_TYPE_P(moduleName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'moduleName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(moduleName_param) == IS_STRING)) {
		zephir_get_strval(&moduleName, moduleName_param);
	} else {
		ZEPHIR_INIT_VAR(&moduleName);
		ZVAL_EMPTY_STRING(&moduleName);
	}


	zephir_update_property_zval(this_ptr, SL("_defaultModule"), &moduleName);
	RETURN_THIS();

}

/**
 * Sets the default controller name
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultController) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *controllerName_param = NULL;
	zval controllerName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controllerName_param);

	if (UNEXPECTED(Z_TYPE_P(controllerName_param) != IS_STRING && Z_TYPE_P(controllerName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controllerName_param) == IS_STRING)) {
		zephir_get_strval(&controllerName, controllerName_param);
	} else {
		ZEPHIR_INIT_VAR(&controllerName);
		ZVAL_EMPTY_STRING(&controllerName);
	}


	zephir_update_property_zval(this_ptr, SL("_defaultController"), &controllerName);
	RETURN_THIS();

}

/**
 * Sets the default action name
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaultAction) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *actionName_param = NULL;
	zval actionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionName_param);

	if (UNEXPECTED(Z_TYPE_P(actionName_param) != IS_STRING && Z_TYPE_P(actionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'actionName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(actionName_param) == IS_STRING)) {
		zephir_get_strval(&actionName, actionName_param);
	} else {
		ZEPHIR_INIT_VAR(&actionName);
		ZVAL_EMPTY_STRING(&actionName);
	}


	zephir_update_property_zval(this_ptr, SL("_defaultAction"), &actionName);
	RETURN_THIS();

}

/**
 * Sets an array of default paths. If a route is missing a path the router will use the defined here
 * This method must not be used to set a 404 route
 *
 *<code>
 * $router->setDefaults(
 *     [
 *         "module" => "common",
 *         "action" => "index",
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Router, setDefaults) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *defaults_param = NULL, namespaceName, module, controller, action, params;
	zval defaults;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaults_param);

	ZEPHIR_OBS_COPY_OR_DUP(&defaults, defaults_param);


	if (zephir_array_isset_string_fetch(&namespaceName, &defaults, SL("namespace"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_defaultNamespace"), &namespaceName);
	}
	if (zephir_array_isset_string_fetch(&module, &defaults, SL("module"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_defaultModule"), &module);
	}
	if (zephir_array_isset_string_fetch(&controller, &defaults, SL("controller"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_defaultController"), &controller);
	}
	if (zephir_array_isset_string_fetch(&action, &defaults, SL("action"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_defaultAction"), &action);
	}
	if (zephir_array_isset_string_fetch(&params, &defaults, SL("params"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_defaultParams"), &params);
	}
	RETURN_THIS();

}

/**
 * Returns an array of default parameters
 */
PHP_METHOD(Phalcon_Mvc_Router, getDefaults) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 5, 0);
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("namespace"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("module"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_defaultController"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("controller"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("action"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_defaultParams"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("params"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Handles routing information received from the rewrite engine
 *
 *<code>
 * // Read the info from the rewrite engine
 * $router->handle();
 *
 * // Manually passing an URL
 * $router->handle("/posts/edit/1");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Router, handle) {

	zend_string *_26$$34, *_61$$83;
	zend_ulong _25$$34, _60$$83;
	zval _20$$29, _32$$40, _34$$43, _39$$51, _41$$54, _55$$78, _66$$89, _68$$92, _73$$100, _75$$103;
	zend_bool _1, _30$$35, _37$$46, _64$$84, _71$$95;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_17 = NULL, *_19 = NULL, *_22 = NULL, *_29 = NULL, *_52 = NULL, *_54 = NULL, *_57 = NULL, *_76 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, __$true, __$false, __$null, realUri, request, currentHostName, routeFound, parts, params, matches, notFoundPaths, vnamespace, module, controller, action, paramsStr, strParams, route, methods, dependencyInjector, hostname, regexHostName, matched, pattern, handledUri, beforeMatch, paths, converters, part, position, matchPosition, converter, eventsManager, _0, _4, *_5, _6, _77, _78, _79, _80, _81, _2$$5, _3$$7, _7$$10, _8$$10, _9$$10, _10$$9, _11$$9, _12$$14, _13$$14, _14$$14, _15$$18, _16$$24, _18$$28, _21$$32, *_23$$34, _24$$34, _27$$36, _28$$36, _31$$40, _33$$43, _35$$47, _36$$47, _38$$51, _40$$54, _42$$59, _43$$59, _44$$59, _45$$58, _46$$58, _47$$63, _48$$63, _49$$63, _50$$67, _51$$73, _53$$77, _56$$81, *_58$$83, _59$$83, _62$$85, _63$$85, _65$$89, _67$$92, _69$$96, _70$$96, _72$$100, _74$$103, _82$$120, _83$$122, _84$$124;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&realUri);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&currentHostName);
	ZVAL_UNDEF(&routeFound);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&notFoundPaths);
	ZVAL_UNDEF(&vnamespace);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&paramsStr);
	ZVAL_UNDEF(&strParams);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&hostname);
	ZVAL_UNDEF(&regexHostName);
	ZVAL_UNDEF(&matched);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&handledUri);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&converters);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&matchPosition);
	ZVAL_UNDEF(&converter);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_77);
	ZVAL_UNDEF(&_78);
	ZVAL_UNDEF(&_79);
	ZVAL_UNDEF(&_80);
	ZVAL_UNDEF(&_81);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$18);
	ZVAL_UNDEF(&_16$$24);
	ZVAL_UNDEF(&_18$$28);
	ZVAL_UNDEF(&_21$$32);
	ZVAL_UNDEF(&_24$$34);
	ZVAL_UNDEF(&_27$$36);
	ZVAL_UNDEF(&_28$$36);
	ZVAL_UNDEF(&_31$$40);
	ZVAL_UNDEF(&_33$$43);
	ZVAL_UNDEF(&_35$$47);
	ZVAL_UNDEF(&_36$$47);
	ZVAL_UNDEF(&_38$$51);
	ZVAL_UNDEF(&_40$$54);
	ZVAL_UNDEF(&_42$$59);
	ZVAL_UNDEF(&_43$$59);
	ZVAL_UNDEF(&_44$$59);
	ZVAL_UNDEF(&_45$$58);
	ZVAL_UNDEF(&_46$$58);
	ZVAL_UNDEF(&_47$$63);
	ZVAL_UNDEF(&_48$$63);
	ZVAL_UNDEF(&_49$$63);
	ZVAL_UNDEF(&_50$$67);
	ZVAL_UNDEF(&_51$$73);
	ZVAL_UNDEF(&_53$$77);
	ZVAL_UNDEF(&_56$$81);
	ZVAL_UNDEF(&_59$$83);
	ZVAL_UNDEF(&_62$$85);
	ZVAL_UNDEF(&_63$$85);
	ZVAL_UNDEF(&_65$$89);
	ZVAL_UNDEF(&_67$$92);
	ZVAL_UNDEF(&_69$$96);
	ZVAL_UNDEF(&_70$$96);
	ZVAL_UNDEF(&_72$$100);
	ZVAL_UNDEF(&_74$$103);
	ZVAL_UNDEF(&_82$$120);
	ZVAL_UNDEF(&_83$$122);
	ZVAL_UNDEF(&_84$$124);
	ZVAL_UNDEF(&_20$$29);
	ZVAL_UNDEF(&_32$$40);
	ZVAL_UNDEF(&_34$$43);
	ZVAL_UNDEF(&_39$$51);
	ZVAL_UNDEF(&_41$$54);
	ZVAL_UNDEF(&_55$$78);
	ZVAL_UNDEF(&_66$$89);
	ZVAL_UNDEF(&_68$$92);
	ZVAL_UNDEF(&_73$$100);
	ZVAL_UNDEF(&_75$$103);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri_param);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_STRING(&uri, "");
	} else {
		zephir_get_strval(&uri, uri_param);
	}


	if (!(!(Z_TYPE_P(&uri) == IS_UNDEF) && Z_STRLEN_P(&uri))) {
		ZEPHIR_CALL_METHOD(&realUri, this_ptr, "getrewriteuri", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&realUri, &uri);
	}
	zephir_read_property(&_0, this_ptr, SL("_removeExtraSlashes"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_is_true(&_0);
	if (_1) {
		_1 = !ZEPHIR_IS_STRING(&realUri, "/");
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "/");
		ZEPHIR_INIT_VAR(&handledUri);
		zephir_fast_trim(&handledUri, &realUri, &_2$$5, ZEPHIR_TRIM_RIGHT);
	} else {
		ZEPHIR_CPY_WRT(&handledUri, &realUri);
	}
	ZEPHIR_INIT_VAR(&request);
	ZVAL_NULL(&request);
	ZEPHIR_INIT_VAR(&currentHostName);
	ZVAL_NULL(&currentHostName);
	ZEPHIR_INIT_VAR(&routeFound);
	ZVAL_BOOL(&routeFound, 0);
	ZEPHIR_INIT_VAR(&parts);
	array_init(&parts);
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	ZEPHIR_INIT_VAR(&matches);
	ZVAL_NULL(&matches);
	if (0) {
		zephir_update_property_zval(this_ptr, SL("_wasMatched"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_wasMatched"), &__$false);
	}
	zephir_update_property_zval(this_ptr, SL("_matchedRoute"), &__$null);
	ZEPHIR_OBS_VAR(&eventsManager);
	zephir_read_property(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_3$$7);
		ZVAL_STRING(&_3$$7, "router:beforeCheckRoutes");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_3$$7, this_ptr);
		zephir_check_call_status();
	}
	zephir_read_property(&_4, this_ptr, SL("_routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_4, 0, "phalcon/mvc/router.zep", 586);
	if (Z_TYPE_P(&_4) == IS_ARRAY) {
		ZEND_HASH_REVERSE_FOREACH_VAL(Z_ARRVAL_P(&_4), _5)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _5);
			ZEPHIR_INIT_NVAR(&params);
			array_init(&params);
			ZEPHIR_INIT_NVAR(&matches);
			ZVAL_NULL(&matches);
			ZEPHIR_CALL_METHOD(&methods, &route, "gethttpmethods", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&methods) != IS_NULL) {
				if (Z_TYPE_P(&request) == IS_NULL) {
					zephir_read_property(&_7$$10, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CPY_WRT(&dependencyInjector, &_7$$10);
					if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'request' service", "phalcon/mvc/router.zep", 391);
						return;
					}
					ZEPHIR_INIT_NVAR(&_9$$10);
					ZVAL_STRING(&_9$$10, "request");
					ZEPHIR_CALL_METHOD(&_8$$10, &dependencyInjector, "getshared", NULL, 0, &_9$$10);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&request, &_8$$10);
				}
				ZVAL_BOOL(&_11$$9, 1);
				ZEPHIR_CALL_METHOD(&_10$$9, &request, "ismethod", NULL, 0, &methods, &_11$$9);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_10$$9)) {
					continue;
				}
			}
			ZEPHIR_CALL_METHOD(&hostname, &route, "gethostname", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&hostname) != IS_NULL) {
				if (Z_TYPE_P(&request) == IS_NULL) {
					zephir_read_property(&_12$$14, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CPY_WRT(&dependencyInjector, &_12$$14);
					if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'request' service", "phalcon/mvc/router.zep", 418);
						return;
					}
					ZEPHIR_INIT_NVAR(&_14$$14);
					ZVAL_STRING(&_14$$14, "request");
					ZEPHIR_CALL_METHOD(&_13$$14, &dependencyInjector, "getshared", NULL, 0, &_14$$14);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&request, &_13$$14);
				}
				if (Z_TYPE_P(&currentHostName) == IS_NULL) {
					ZEPHIR_CALL_METHOD(&currentHostName, &request, "gethttphost", NULL, 0);
					zephir_check_call_status();
				}
				if (!(zephir_is_true(&currentHostName))) {
					continue;
				}
				if (zephir_memnstr_str(&hostname, SL("("), "phalcon/mvc/router.zep", 441)) {
					if (!(zephir_memnstr_str(&hostname, SL("#"), "phalcon/mvc/router.zep", 442))) {
						ZEPHIR_INIT_NVAR(&regexHostName);
						ZEPHIR_CONCAT_SV(&regexHostName, "#^", &hostname);
						if (!(zephir_memnstr_str(&hostname, SL(":"), "phalcon/mvc/router.zep", 444))) {
							zephir_concat_self_str(&regexHostName, SL("(:[[:digit:]]+)?"));
						}
						zephir_concat_self_str(&regexHostName, SL("$#i"));
					} else {
						ZEPHIR_CPY_WRT(&regexHostName, &hostname);
					}
					ZEPHIR_INIT_NVAR(&_15$$18);
					ZEPHIR_INIT_NVAR(&matched);
					zephir_preg_match(&matched, &regexHostName, &currentHostName, &_15$$18, 0, 0 , 0 );
				} else {
					ZEPHIR_INIT_NVAR(&matched);
					ZVAL_BOOL(&matched, ZEPHIR_IS_EQUAL(&currentHostName, &hostname));
				}
				if (!(zephir_is_true(&matched))) {
					continue;
				}
			}
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(&_16$$24);
				ZVAL_STRING(&_16$$24, "router:beforeCheckRoute");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_17, 0, &_16$$24, this_ptr, &route);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&pattern, &route, "getcompiledpattern", NULL, 0);
			zephir_check_call_status();
			if (zephir_memnstr_str(&pattern, SL("^"), "phalcon/mvc/router.zep", 470)) {
				ZEPHIR_INIT_NVAR(&routeFound);
				zephir_preg_match(&routeFound, &pattern, &handledUri, &matches, 0, 0 , 0 );
			} else {
				ZEPHIR_INIT_NVAR(&routeFound);
				ZVAL_BOOL(&routeFound, ZEPHIR_IS_EQUAL(&pattern, &handledUri));
			}
			if (zephir_is_true(&routeFound)) {
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_18$$28);
					ZVAL_STRING(&_18$$28, "router:matchedRoute");
					ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_19, 0, &_18$$28, this_ptr, &route);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&beforeMatch, &route, "getbeforematch", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
					if (!(zephir_is_callable(&beforeMatch))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Before-Match callback is not callable in matched route", "phalcon/mvc/router.zep", 492);
						return;
					}
					ZEPHIR_INIT_NVAR(&_20$$29);
					zephir_create_array(&_20$$29, 3, 0);
					zephir_array_fast_append(&_20$$29, &handledUri);
					zephir_array_fast_append(&_20$$29, &route);
					zephir_array_fast_append(&_20$$29, this_ptr);
					ZEPHIR_INIT_NVAR(&routeFound);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&routeFound, &beforeMatch, &_20$$29);
					zephir_check_call_status();
				}
			} else {
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_21$$32);
					ZVAL_STRING(&_21$$32, "router:notMatchedRoute");
					ZEPHIR_CALL_METHOD(&routeFound, &eventsManager, "fire", &_22, 0, &_21$$32, this_ptr, &route);
					zephir_check_call_status();
				}
			}
			if (zephir_is_true(&routeFound)) {
				ZEPHIR_CALL_METHOD(&paths, &route, "getpaths", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&parts, &paths);
				if (Z_TYPE_P(&matches) == IS_ARRAY) {
					ZEPHIR_CALL_METHOD(&converters, &route, "getconverters", NULL, 0);
					zephir_check_call_status();
					zephir_is_iterable(&paths, 0, "phalcon/mvc/router.zep", 575);
					if (Z_TYPE_P(&paths) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paths), _25$$34, _26$$34, _23$$34)
						{
							ZEPHIR_INIT_NVAR(&part);
							if (_26$$34 != NULL) { 
								ZVAL_STR_COPY(&part, _26$$34);
							} else {
								ZVAL_LONG(&part, _25$$34);
							}
							ZEPHIR_INIT_NVAR(&position);
							ZVAL_COPY(&position, _23$$34);
							if (Z_TYPE_P(&part) != IS_STRING) {
								ZEPHIR_INIT_NVAR(&_27$$36);
								object_init_ex(&_27$$36, phalcon_mvc_router_exception_ce);
								ZEPHIR_INIT_NVAR(&_28$$36);
								ZEPHIR_CONCAT_SV(&_28$$36, "Wrong key in paths: ", &part);
								ZEPHIR_CALL_METHOD(NULL, &_27$$36, "__construct", &_29, 4, &_28$$36);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_27$$36, "phalcon/mvc/router.zep", 528);
								ZEPHIR_MM_RESTORE();
								return;
							}
							_30$$35 = Z_TYPE_P(&position) != IS_STRING;
							if (_30$$35) {
								_30$$35 = Z_TYPE_P(&position) != IS_LONG;
							}
							if (_30$$35) {
								continue;
							}
							ZEPHIR_OBS_NVAR(&matchPosition);
							if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
								if (Z_TYPE_P(&converters) == IS_ARRAY) {
									ZEPHIR_OBS_NVAR(&converter);
									if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
										ZEPHIR_INIT_NVAR(&_31$$40);
										ZEPHIR_INIT_NVAR(&_32$$40);
										zephir_create_array(&_32$$40, 1, 0);
										zephir_array_fast_append(&_32$$40, &matchPosition);
										ZEPHIR_CALL_USER_FUNC_ARRAY(&_31$$40, &converter, &_32$$40);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &part, &_31$$40, PH_COPY | PH_SEPARATE);
										continue;
									}
								}
								zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
							} else {
								if (Z_TYPE_P(&converters) == IS_ARRAY) {
									ZEPHIR_OBS_NVAR(&converter);
									if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
										ZEPHIR_INIT_NVAR(&_33$$43);
										ZEPHIR_INIT_NVAR(&_34$$43);
										zephir_create_array(&_34$$43, 1, 0);
										zephir_array_fast_append(&_34$$43, &position);
										ZEPHIR_CALL_USER_FUNC_ARRAY(&_33$$43, &converter, &_34$$43);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &part, &_33$$43, PH_COPY | PH_SEPARATE);
									}
								} else {
									if (Z_TYPE_P(&position) == IS_LONG) {
										zephir_array_unset(&parts, &part, PH_SEPARATE);
									}
								}
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &paths, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_24$$34, &paths, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_24$$34)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&part, &paths, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&position, &paths, "current", NULL, 0);
							zephir_check_call_status();
								if (Z_TYPE_P(&part) != IS_STRING) {
									ZEPHIR_INIT_NVAR(&_35$$47);
									object_init_ex(&_35$$47, phalcon_mvc_router_exception_ce);
									ZEPHIR_INIT_NVAR(&_36$$47);
									ZEPHIR_CONCAT_SV(&_36$$47, "Wrong key in paths: ", &part);
									ZEPHIR_CALL_METHOD(NULL, &_35$$47, "__construct", &_29, 4, &_36$$47);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_35$$47, "phalcon/mvc/router.zep", 528);
									ZEPHIR_MM_RESTORE();
									return;
								}
								_37$$46 = Z_TYPE_P(&position) != IS_STRING;
								if (_37$$46) {
									_37$$46 = Z_TYPE_P(&position) != IS_LONG;
								}
								if (_37$$46) {
									continue;
								}
								ZEPHIR_OBS_NVAR(&matchPosition);
								if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
									if (Z_TYPE_P(&converters) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_INIT_NVAR(&_38$$51);
											ZEPHIR_INIT_NVAR(&_39$$51);
											zephir_create_array(&_39$$51, 1, 0);
											zephir_array_fast_append(&_39$$51, &matchPosition);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_38$$51, &converter, &_39$$51);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_38$$51, PH_COPY | PH_SEPARATE);
											continue;
										}
									}
									zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
								} else {
									if (Z_TYPE_P(&converters) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_INIT_NVAR(&_40$$54);
											ZEPHIR_INIT_NVAR(&_41$$54);
											zephir_create_array(&_41$$54, 1, 0);
											zephir_array_fast_append(&_41$$54, &position);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_40$$54, &converter, &_41$$54);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_40$$54, PH_COPY | PH_SEPARATE);
										}
									} else {
										if (Z_TYPE_P(&position) == IS_LONG) {
											zephir_array_unset(&parts, &part, PH_SEPARATE);
										}
									}
								}
							ZEPHIR_CALL_METHOD(NULL, &paths, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&position);
					ZEPHIR_INIT_NVAR(&part);
					zephir_update_property_zval(this_ptr, SL("_matches"), &matches);
				}
				zephir_update_property_zval(this_ptr, SL("_matchedRoute"), &route);
				break;
			}
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
			ZEPHIR_CALL_METHOD(&route, &_4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&params);
				array_init(&params);
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_NULL(&matches);
				ZEPHIR_CALL_METHOD(&methods, &route, "gethttpmethods", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&methods) != IS_NULL) {
					if (Z_TYPE_P(&request) == IS_NULL) {
						zephir_read_property(&_42$$59, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CPY_WRT(&dependencyInjector, &_42$$59);
						if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'request' service", "phalcon/mvc/router.zep", 391);
							return;
						}
						ZEPHIR_INIT_NVAR(&_44$$59);
						ZVAL_STRING(&_44$$59, "request");
						ZEPHIR_CALL_METHOD(&_43$$59, &dependencyInjector, "getshared", NULL, 0, &_44$$59);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&request, &_43$$59);
					}
					ZVAL_BOOL(&_46$$58, 1);
					ZEPHIR_CALL_METHOD(&_45$$58, &request, "ismethod", NULL, 0, &methods, &_46$$58);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_45$$58)) {
						continue;
					}
				}
				ZEPHIR_CALL_METHOD(&hostname, &route, "gethostname", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&hostname) != IS_NULL) {
					if (Z_TYPE_P(&request) == IS_NULL) {
						zephir_read_property(&_47$$63, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CPY_WRT(&dependencyInjector, &_47$$63);
						if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'request' service", "phalcon/mvc/router.zep", 418);
							return;
						}
						ZEPHIR_INIT_NVAR(&_49$$63);
						ZVAL_STRING(&_49$$63, "request");
						ZEPHIR_CALL_METHOD(&_48$$63, &dependencyInjector, "getshared", NULL, 0, &_49$$63);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&request, &_48$$63);
					}
					if (Z_TYPE_P(&currentHostName) == IS_NULL) {
						ZEPHIR_CALL_METHOD(&currentHostName, &request, "gethttphost", NULL, 0);
						zephir_check_call_status();
					}
					if (!(zephir_is_true(&currentHostName))) {
						continue;
					}
					if (zephir_memnstr_str(&hostname, SL("("), "phalcon/mvc/router.zep", 441)) {
						if (!(zephir_memnstr_str(&hostname, SL("#"), "phalcon/mvc/router.zep", 442))) {
							ZEPHIR_INIT_NVAR(&regexHostName);
							ZEPHIR_CONCAT_SV(&regexHostName, "#^", &hostname);
							if (!(zephir_memnstr_str(&hostname, SL(":"), "phalcon/mvc/router.zep", 444))) {
								zephir_concat_self_str(&regexHostName, SL("(:[[:digit:]]+)?"));
							}
							zephir_concat_self_str(&regexHostName, SL("$#i"));
						} else {
							ZEPHIR_CPY_WRT(&regexHostName, &hostname);
						}
						ZEPHIR_INIT_NVAR(&_50$$67);
						ZEPHIR_INIT_NVAR(&matched);
						zephir_preg_match(&matched, &regexHostName, &currentHostName, &_50$$67, 0, 0 , 0 );
					} else {
						ZEPHIR_INIT_NVAR(&matched);
						ZVAL_BOOL(&matched, ZEPHIR_IS_EQUAL(&currentHostName, &hostname));
					}
					if (!(zephir_is_true(&matched))) {
						continue;
					}
				}
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_51$$73);
					ZVAL_STRING(&_51$$73, "router:beforeCheckRoute");
					ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_52, 0, &_51$$73, this_ptr, &route);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&pattern, &route, "getcompiledpattern", NULL, 0);
				zephir_check_call_status();
				if (zephir_memnstr_str(&pattern, SL("^"), "phalcon/mvc/router.zep", 470)) {
					ZEPHIR_INIT_NVAR(&routeFound);
					zephir_preg_match(&routeFound, &pattern, &handledUri, &matches, 0, 0 , 0 );
				} else {
					ZEPHIR_INIT_NVAR(&routeFound);
					ZVAL_BOOL(&routeFound, ZEPHIR_IS_EQUAL(&pattern, &handledUri));
				}
				if (zephir_is_true(&routeFound)) {
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_53$$77);
						ZVAL_STRING(&_53$$77, "router:matchedRoute");
						ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_54, 0, &_53$$77, this_ptr, &route);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&beforeMatch, &route, "getbeforematch", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
						if (!(zephir_is_callable(&beforeMatch))) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Before-Match callback is not callable in matched route", "phalcon/mvc/router.zep", 492);
							return;
						}
						ZEPHIR_INIT_NVAR(&_55$$78);
						zephir_create_array(&_55$$78, 3, 0);
						zephir_array_fast_append(&_55$$78, &handledUri);
						zephir_array_fast_append(&_55$$78, &route);
						zephir_array_fast_append(&_55$$78, this_ptr);
						ZEPHIR_INIT_NVAR(&routeFound);
						ZEPHIR_CALL_USER_FUNC_ARRAY(&routeFound, &beforeMatch, &_55$$78);
						zephir_check_call_status();
					}
				} else {
					if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_56$$81);
						ZVAL_STRING(&_56$$81, "router:notMatchedRoute");
						ZEPHIR_CALL_METHOD(&routeFound, &eventsManager, "fire", &_57, 0, &_56$$81, this_ptr, &route);
						zephir_check_call_status();
					}
				}
				if (zephir_is_true(&routeFound)) {
					ZEPHIR_CALL_METHOD(&paths, &route, "getpaths", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&parts, &paths);
					if (Z_TYPE_P(&matches) == IS_ARRAY) {
						ZEPHIR_CALL_METHOD(&converters, &route, "getconverters", NULL, 0);
						zephir_check_call_status();
						zephir_is_iterable(&paths, 0, "phalcon/mvc/router.zep", 575);
						if (Z_TYPE_P(&paths) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paths), _60$$83, _61$$83, _58$$83)
							{
								ZEPHIR_INIT_NVAR(&part);
								if (_61$$83 != NULL) { 
									ZVAL_STR_COPY(&part, _61$$83);
								} else {
									ZVAL_LONG(&part, _60$$83);
								}
								ZEPHIR_INIT_NVAR(&position);
								ZVAL_COPY(&position, _58$$83);
								if (Z_TYPE_P(&part) != IS_STRING) {
									ZEPHIR_INIT_NVAR(&_62$$85);
									object_init_ex(&_62$$85, phalcon_mvc_router_exception_ce);
									ZEPHIR_INIT_NVAR(&_63$$85);
									ZEPHIR_CONCAT_SV(&_63$$85, "Wrong key in paths: ", &part);
									ZEPHIR_CALL_METHOD(NULL, &_62$$85, "__construct", &_29, 4, &_63$$85);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_62$$85, "phalcon/mvc/router.zep", 528);
									ZEPHIR_MM_RESTORE();
									return;
								}
								_64$$84 = Z_TYPE_P(&position) != IS_STRING;
								if (_64$$84) {
									_64$$84 = Z_TYPE_P(&position) != IS_LONG;
								}
								if (_64$$84) {
									continue;
								}
								ZEPHIR_OBS_NVAR(&matchPosition);
								if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
									if (Z_TYPE_P(&converters) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_INIT_NVAR(&_65$$89);
											ZEPHIR_INIT_NVAR(&_66$$89);
											zephir_create_array(&_66$$89, 1, 0);
											zephir_array_fast_append(&_66$$89, &matchPosition);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_65$$89, &converter, &_66$$89);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_65$$89, PH_COPY | PH_SEPARATE);
											continue;
										}
									}
									zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
								} else {
									if (Z_TYPE_P(&converters) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_INIT_NVAR(&_67$$92);
											ZEPHIR_INIT_NVAR(&_68$$92);
											zephir_create_array(&_68$$92, 1, 0);
											zephir_array_fast_append(&_68$$92, &position);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_67$$92, &converter, &_68$$92);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_67$$92, PH_COPY | PH_SEPARATE);
										}
									} else {
										if (Z_TYPE_P(&position) == IS_LONG) {
											zephir_array_unset(&parts, &part, PH_SEPARATE);
										}
									}
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &paths, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_59$$83, &paths, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_59$$83)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&part, &paths, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&position, &paths, "current", NULL, 0);
								zephir_check_call_status();
									if (Z_TYPE_P(&part) != IS_STRING) {
										ZEPHIR_INIT_NVAR(&_69$$96);
										object_init_ex(&_69$$96, phalcon_mvc_router_exception_ce);
										ZEPHIR_INIT_NVAR(&_70$$96);
										ZEPHIR_CONCAT_SV(&_70$$96, "Wrong key in paths: ", &part);
										ZEPHIR_CALL_METHOD(NULL, &_69$$96, "__construct", &_29, 4, &_70$$96);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_69$$96, "phalcon/mvc/router.zep", 528);
										ZEPHIR_MM_RESTORE();
										return;
									}
									_71$$95 = Z_TYPE_P(&position) != IS_STRING;
									if (_71$$95) {
										_71$$95 = Z_TYPE_P(&position) != IS_LONG;
									}
									if (_71$$95) {
										continue;
									}
									ZEPHIR_OBS_NVAR(&matchPosition);
									if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
										if (Z_TYPE_P(&converters) == IS_ARRAY) {
											ZEPHIR_OBS_NVAR(&converter);
											if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
												ZEPHIR_INIT_NVAR(&_72$$100);
												ZEPHIR_INIT_NVAR(&_73$$100);
												zephir_create_array(&_73$$100, 1, 0);
												zephir_array_fast_append(&_73$$100, &matchPosition);
												ZEPHIR_CALL_USER_FUNC_ARRAY(&_72$$100, &converter, &_73$$100);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_72$$100, PH_COPY | PH_SEPARATE);
												continue;
											}
										}
										zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
									} else {
										if (Z_TYPE_P(&converters) == IS_ARRAY) {
											ZEPHIR_OBS_NVAR(&converter);
											if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
												ZEPHIR_INIT_NVAR(&_74$$103);
												ZEPHIR_INIT_NVAR(&_75$$103);
												zephir_create_array(&_75$$103, 1, 0);
												zephir_array_fast_append(&_75$$103, &position);
												ZEPHIR_CALL_USER_FUNC_ARRAY(&_74$$103, &converter, &_75$$103);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_74$$103, PH_COPY | PH_SEPARATE);
											}
										} else {
											if (Z_TYPE_P(&position) == IS_LONG) {
												zephir_array_unset(&parts, &part, PH_SEPARATE);
											}
										}
									}
								ZEPHIR_CALL_METHOD(NULL, &paths, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&position);
						ZEPHIR_INIT_NVAR(&part);
						zephir_update_property_zval(this_ptr, SL("_matches"), &matches);
					}
					zephir_update_property_zval(this_ptr, SL("_matchedRoute"), &route);
					break;
				}
			ZEPHIR_CALL_METHOD(NULL, &_4, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	if (zephir_is_true(&routeFound)) {
		if (1) {
			zephir_update_property_zval(this_ptr, SL("_wasMatched"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_wasMatched"), &__$false);
		}
	} else {
		if (0) {
			zephir_update_property_zval(this_ptr, SL("_wasMatched"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_wasMatched"), &__$false);
		}
	}
	if (!(zephir_is_true(&routeFound))) {
		ZEPHIR_OBS_VAR(&notFoundPaths);
		zephir_read_property(&notFoundPaths, this_ptr, SL("_notFoundPaths"), PH_NOISY_CC);
		if (Z_TYPE_P(&notFoundPaths) != IS_NULL) {
			ZEPHIR_CALL_CE_STATIC(&parts, phalcon_mvc_router_route_ce, "getroutepaths", &_76, 0, &notFoundPaths);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&routeFound);
			ZVAL_BOOL(&routeFound, 1);
		}
	}
	zephir_read_property(&_77, this_ptr, SL("_defaultNamespace"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("_namespace"), &_77);
	zephir_read_property(&_78, this_ptr, SL("_defaultModule"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("_module"), &_78);
	zephir_read_property(&_79, this_ptr, SL("_defaultController"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("_controller"), &_79);
	zephir_read_property(&_80, this_ptr, SL("_defaultAction"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("_action"), &_80);
	zephir_read_property(&_81, this_ptr, SL("_defaultParams"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("_params"), &_81);
	if (zephir_is_true(&routeFound)) {
		ZEPHIR_OBS_VAR(&vnamespace);
		if (zephir_array_isset_string_fetch(&vnamespace, &parts, SL("namespace"), 0)) {
			if (!(zephir_is_numeric(&vnamespace))) {
				zephir_update_property_zval(this_ptr, SL("_namespace"), &vnamespace);
			}
			zephir_array_unset_string(&parts, SL("namespace"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(&module);
		if (zephir_array_isset_string_fetch(&module, &parts, SL("module"), 0)) {
			if (!(zephir_is_numeric(&module))) {
				zephir_update_property_zval(this_ptr, SL("_module"), &module);
			}
			zephir_array_unset_string(&parts, SL("module"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(&controller);
		if (zephir_array_isset_string_fetch(&controller, &parts, SL("controller"), 0)) {
			if (!(zephir_is_numeric(&controller))) {
				zephir_update_property_zval(this_ptr, SL("_controller"), &controller);
			}
			zephir_array_unset_string(&parts, SL("controller"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(&action);
		if (zephir_array_isset_string_fetch(&action, &parts, SL("action"), 0)) {
			if (!(zephir_is_numeric(&action))) {
				zephir_update_property_zval(this_ptr, SL("_action"), &action);
			}
			zephir_array_unset_string(&parts, SL("action"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(&paramsStr);
		if (zephir_array_isset_string_fetch(&paramsStr, &parts, SL("params"), 0)) {
			if (Z_TYPE_P(&paramsStr) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_82$$120);
				ZVAL_STRING(&_82$$120, "/");
				ZEPHIR_INIT_VAR(&strParams);
				zephir_fast_trim(&strParams, &paramsStr, &_82$$120, ZEPHIR_TRIM_BOTH);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&strParams, "")) {
					ZEPHIR_INIT_NVAR(&params);
					zephir_fast_explode_str(&params, SL("/"), &strParams, LONG_MAX);
				}
			}
			zephir_array_unset_string(&parts, SL("params"), PH_SEPARATE);
		}
		if (zephir_fast_count_int(&params)) {
			ZEPHIR_INIT_VAR(&_83$$122);
			zephir_fast_array_merge(&_83$$122, &params, &parts);
			zephir_update_property_zval(this_ptr, SL("_params"), &_83$$122);
		} else {
			zephir_update_property_zval(this_ptr, SL("_params"), &parts);
		}
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_84$$124);
		ZVAL_STRING(&_84$$124, "router:afterCheckRoutes");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_84$$124, this_ptr);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Attach Route object to the routes stack.
 *
 * <code>
 * use Phalcon\Mvc\Router;
 * use Phalcon\Mvc\Router\Route;
 *
 * class CustomRoute extends Route {
 *      // ...
 * }
 *
 * $router = new Router();
 *
 * $router->attach(
 *     new CustomRoute("/about", "About::index", ["GET", "HEAD"]),
 *     Router::POSITION_FIRST
 * );
 * </code>
 *
 * @todo Add to the interface for 4.0.0
 */
PHP_METHOD(Phalcon_Mvc_Router, attach) {

	zval _1$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *route, route_sub, *position = NULL, position_sub, _0$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &route, &position);

	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	do {
		if (ZEPHIR_IS_LONG(position, 1)) {
			zephir_update_property_array_append(this_ptr, SL("_routes"), route);
			break;
		}
		if (ZEPHIR_IS_LONG(position, 0)) {
			ZEPHIR_INIT_VAR(&_0$$4);
			ZEPHIR_INIT_VAR(&_1$$4);
			zephir_create_array(&_1$$4, 1, 0);
			zephir_array_fast_append(&_1$$4, route);
			zephir_read_property(&_2$$4, this_ptr, SL("_routes"), PH_NOISY_CC | PH_READONLY);
			zephir_fast_array_merge(&_0$$4, &_1$$4, &_2$$4);
			zephir_update_property_zval(this_ptr, SL("_routes"), &_0$$4);
			break;
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "Invalid route position", "phalcon/mvc/router.zep", 711);
		return;
	} while(0);

	RETURN_THIS();

}

/**
 * Adds a route to the router without any HTTP constraint
 *
 *<code>
 * use Phalcon\Mvc\Router;
 *
 * $router->add("/about", "About::index");
 * $router->add("/about", "About::index", ["GET", "POST"]);
 * $router->add("/about", "About::index", ["GET", "POST"], Router::POSITION_FIRST);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Router, add) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *httpMethods = NULL, httpMethods_sub, *position = NULL, position_sub, __$null, route;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&httpMethods_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&route);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &pattern_param, &paths, &httpMethods, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!httpMethods) {
		httpMethods = &httpMethods_sub;
		httpMethods = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&route);
	object_init_ex(&route, phalcon_mvc_router_route_ce);
	ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 74, &pattern, paths, httpMethods);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", NULL, 0, &route, position);
	zephir_check_call_status();
	RETURN_CCTOR(&route);

}

/**
 * Adds a route to the router that only match if the HTTP method is GET
 */
PHP_METHOD(Phalcon_Mvc_Router, addGet) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "GET");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is POST
 */
PHP_METHOD(Phalcon_Mvc_Router, addPost) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "POST");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PUT
 */
PHP_METHOD(Phalcon_Mvc_Router, addPut) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PUT");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PATCH
 */
PHP_METHOD(Phalcon_Mvc_Router, addPatch) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PATCH");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 */
PHP_METHOD(Phalcon_Mvc_Router, addDelete) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "DELETE");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 */
PHP_METHOD(Phalcon_Mvc_Router, addOptions) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "OPTIONS");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 */
PHP_METHOD(Phalcon_Mvc_Router, addHead) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HEAD");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is PURGE (Squid and Varnish support)
 */
PHP_METHOD(Phalcon_Mvc_Router, addPurge) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PURGE");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is TRACE
 */
PHP_METHOD(Phalcon_Mvc_Router, addTrace) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "TRACE");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a route to the router that only match if the HTTP method is CONNECT
 */
PHP_METHOD(Phalcon_Mvc_Router, addConnect) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *position = NULL, position_sub, __$null, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&position_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &position);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!position) {
		position = &position_sub;
		ZEPHIR_INIT_VAR(position);
		ZVAL_LONG(position, 1);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "CONNECT");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern, paths, &_0, position);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Mounts a group of routes in the router
 */
PHP_METHOD(Phalcon_Mvc_Router, mount) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *group, group_sub, groupRoutes, beforeMatch, hostname, routes, route, eventsManager, _0$$3, *_1$$5, _2$$5, *_3$$8, _4$$8, _5$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group_sub);
	ZVAL_UNDEF(&groupRoutes);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&hostname);
	ZVAL_UNDEF(&routes);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group);



	ZEPHIR_OBS_VAR(&eventsManager);
	zephir_read_property(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "router:beforeMount");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_0$$3, this_ptr, group);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&groupRoutes, group, "getroutes", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(&groupRoutes))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "The group of routes does not contain any routes", "phalcon/mvc/router.zep", 837);
		return;
	}
	ZEPHIR_CALL_METHOD(&beforeMatch, group, "getbeforematch", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
		zephir_is_iterable(&groupRoutes, 0, "phalcon/mvc/router.zep", 849);
		if (Z_TYPE_P(&groupRoutes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&groupRoutes), _1$$5)
			{
				ZEPHIR_INIT_NVAR(&route);
				ZVAL_COPY(&route, _1$$5);
				ZEPHIR_CALL_METHOD(NULL, &route, "beforematch", NULL, 0, &beforeMatch);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &groupRoutes, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$5, &groupRoutes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&route, &groupRoutes, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &route, "beforematch", NULL, 0, &beforeMatch);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &groupRoutes, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&route);
	}
	ZEPHIR_CALL_METHOD(&hostname, group, "gethostname", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&hostname) != IS_NULL) {
		zephir_is_iterable(&groupRoutes, 0, "phalcon/mvc/router.zep", 858);
		if (Z_TYPE_P(&groupRoutes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&groupRoutes), _3$$8)
			{
				ZEPHIR_INIT_NVAR(&route);
				ZVAL_COPY(&route, _3$$8);
				ZEPHIR_CALL_METHOD(NULL, &route, "sethostname", NULL, 0, &hostname);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &groupRoutes, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$8, &groupRoutes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$8)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&route, &groupRoutes, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &route, "sethostname", NULL, 0, &hostname);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &groupRoutes, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&route);
	}
	ZEPHIR_OBS_VAR(&routes);
	zephir_read_property(&routes, this_ptr, SL("_routes"), PH_NOISY_CC);
	if (Z_TYPE_P(&routes) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_5$$11);
		zephir_fast_array_merge(&_5$$11, &routes, &groupRoutes);
		zephir_update_property_zval(this_ptr, SL("_routes"), &_5$$11);
	} else {
		zephir_update_property_zval(this_ptr, SL("_routes"), &groupRoutes);
	}
	RETURN_THIS();

}

/**
 * Set a group of paths to be returned when none of the defined routes are matched
 */
PHP_METHOD(Phalcon_Mvc_Router, notFound) {

	zend_bool _0;
	zval *paths, paths_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&paths_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &paths);



	_0 = Z_TYPE_P(paths) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(paths) != IS_STRING;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_router_exception_ce, "The not-found paths must be an array or string", "phalcon/mvc/router.zep", 877);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("_notFoundPaths"), paths);
	RETURN_THISW();

}

/**
 * Removes all the pre-defined routes
 */
PHP_METHOD(Phalcon_Mvc_Router, clear) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("_routes"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the processed namespace name
 */
PHP_METHOD(Phalcon_Mvc_Router, getNamespaceName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_namespace");

}

/**
 * Returns the processed module name
 */
PHP_METHOD(Phalcon_Mvc_Router, getModuleName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_module");

}

/**
 * Returns the processed controller name
 */
PHP_METHOD(Phalcon_Mvc_Router, getControllerName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_controller");

}

/**
 * Returns the processed action name
 */
PHP_METHOD(Phalcon_Mvc_Router, getActionName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_action");

}

/**
 * Returns the processed parameters
 */
PHP_METHOD(Phalcon_Mvc_Router, getParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_params");

}

/**
 * Returns the route that matches the handled URI
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatchedRoute) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_matchedRoute");

}

/**
 * Returns the sub expressions in the regular expression matched
 */
PHP_METHOD(Phalcon_Mvc_Router, getMatches) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_matches");

}

/**
 * Checks if the router matches any of the defined routes
 */
PHP_METHOD(Phalcon_Mvc_Router, wasMatched) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_wasMatched");

}

/**
 * Returns all the routes defined in the router
 */
PHP_METHOD(Phalcon_Mvc_Router, getRoutes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_routes");

}

/**
 * Returns a route object by its id
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteById) {

	zend_string *_7;
	zend_ulong _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, route, routeId, key, _0, _3, *_4, _5, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&routeId);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	ZEPHIR_OBS_VAR(&key);
	zephir_read_property(&_0, this_ptr, SL("_keyRouteIds"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&key, &_0, id, 0)) {
		zephir_read_property(&_1$$3, this_ptr, SL("_routes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "phalcon/mvc/router.zep", 971);
		RETURN_CTOR(&_2$$3);
	}
	zephir_read_property(&_3, this_ptr, SL("_routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "phalcon/mvc/router.zep", 982);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_3), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&key, _7);
			} else {
				ZVAL_LONG(&key, _6);
			}
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _4);
			ZEPHIR_CALL_METHOD(&routeId, &route, "getrouteid", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("_keyRouteIds"), &routeId, &key);
			if (ZEPHIR_IS_EQUAL(&routeId, id)) {
				RETURN_CCTOR(&route);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_3, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &_3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_3, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&route, &_3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&routeId, &route, "getrouteid", NULL, 0);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("_keyRouteIds"), &routeId, &key);
				if (ZEPHIR_IS_EQUAL(&routeId, id)) {
					RETURN_CCTOR(&route);
				}
			ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_MM_BOOL(0);

}

/**
 * Returns a route object by its name
 */
PHP_METHOD(Phalcon_Mvc_Router, getRouteByName) {

	zend_string *_7;
	zend_ulong _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, route, routeName, key, _0, _3, *_4, _5, _1$$3, _2$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

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


	ZEPHIR_OBS_VAR(&key);
	zephir_read_property(&_0, this_ptr, SL("_keyRouteNames"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&key, &_0, &name, 0)) {
		zephir_read_property(&_1$$3, this_ptr, SL("_routes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "phalcon/mvc/router.zep", 993);
		RETURN_CTOR(&_2$$3);
	}
	zephir_read_property(&_3, this_ptr, SL("_routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "phalcon/mvc/router.zep", 1006);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_3), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&key, _7);
			} else {
				ZVAL_LONG(&key, _6);
			}
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _4);
			ZEPHIR_CALL_METHOD(&routeName, &route, "getname", NULL, 0);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(&routeName))) {
				zephir_update_property_array(this_ptr, SL("_keyRouteNames"), &routeName, &key);
				if (ZEPHIR_IS_EQUAL(&routeName, &name)) {
					RETURN_CCTOR(&route);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_3, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &_3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_3, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&route, &_3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&routeName, &route, "getname", NULL, 0);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&routeName))) {
					zephir_update_property_array(this_ptr, SL("_keyRouteNames"), &routeName, &key);
					if (ZEPHIR_IS_EQUAL(&routeName, &name)) {
						RETURN_CCTOR(&route);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_MM_BOOL(0);

}

/**
 * Returns whether controller name should not be mangled
 */
PHP_METHOD(Phalcon_Mvc_Router, isExactControllerName) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

zend_object *zephir_init_properties_Phalcon_Mvc_Router(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_keyRouteIds"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_keyRouteIds"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("_keyRouteNames"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("_keyRouteNames"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("_defaultParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("_defaultParams"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("_params"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

