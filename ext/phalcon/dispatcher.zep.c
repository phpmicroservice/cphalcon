
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Dispatcher
 *
 * This is the base class for Phalcon\Mvc\Dispatcher and Phalcon\Cli\Dispatcher.
 * This class can't be instantiated directly, you can use it to create your own dispatchers.
 */
ZEPHIR_INIT_CLASS(Phalcon_Dispatcher) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Dispatcher, phalcon, dispatcher, phalcon_dispatcher_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_activeHandler"), ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalcon_dispatcher_ce, SL("_finished"), 0, ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalcon_dispatcher_ce, SL("_forwarded"), 0, ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_moduleName"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_namespaceName"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_handlerName"), ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalcon_dispatcher_ce, SL("_actionName"), "", ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_params"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_returnedValue"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_lastHandler"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_defaultNamespace"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_defaultHandler"), ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalcon_dispatcher_ce, SL("_defaultAction"), "", ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalcon_dispatcher_ce, SL("_handlerSuffix"), "", ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalcon_dispatcher_ce, SL("_actionSuffix"), "Action", ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_previousNamespaceName"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_previousHandlerName"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_previousActionName"), ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalcon_dispatcher_ce, SL("_modelBinding"), 0, ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_dispatcher_ce, SL("_modelBinder"), ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalcon_dispatcher_ce, SL("_isControllerInitialize"), 0, ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalcon_dispatcher_ce, SL("_handlerLasting"), 1, ZEND_ACC_PROTECTED);

	phalcon_dispatcher_ce->create_object = zephir_init_properties_Phalcon_Dispatcher;
	zephir_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_NO_DI"), 0);

	zephir_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_CYCLIC_ROUTING"), 1);

	zephir_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_HANDLER_NOT_FOUND"), 2);

	zephir_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_INVALID_HANDLER"), 3);

	zephir_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_INVALID_PARAMS"), 4);

	zephir_declare_class_constant_long(phalcon_dispatcher_ce, SL("EXCEPTION_ACTION_NOT_FOUND"), 5);

	zend_class_implements(phalcon_dispatcher_ce, 1, phalcon_dispatcherinterface_ce);
	zend_class_implements(phalcon_dispatcher_ce, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_dispatcher_ce, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Dispatcher, setDI) {

	zval *dependencyInjector, dependencyInjector_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &dependencyInjector);



	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Dispatcher, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Dispatcher, setEventsManager) {

	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);



	zephir_update_property_zval(this_ptr, SL("_eventsManager"), eventsManager);

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Dispatcher, getEventsManager) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_eventsManager");

}

/**
 * Sets the default action suffix
 */
PHP_METHOD(Phalcon_Dispatcher, setActionSuffix) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *actionSuffix_param = NULL;
	zval actionSuffix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionSuffix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionSuffix_param);

	zephir_get_strval(&actionSuffix, actionSuffix_param);


	zephir_update_property_zval(this_ptr, SL("_actionSuffix"), &actionSuffix);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the default action suffix
 */
PHP_METHOD(Phalcon_Dispatcher, getActionSuffix) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_actionSuffix");

}

/**
 * Sets the module where the controller is (only informative)
 */
PHP_METHOD(Phalcon_Dispatcher, setModuleName) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *moduleName_param = NULL;
	zval moduleName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

	zephir_get_strval(&moduleName, moduleName_param);


	zephir_update_property_zval(this_ptr, SL("_moduleName"), &moduleName);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the module where the controller class is
 */
PHP_METHOD(Phalcon_Dispatcher, getModuleName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_moduleName");

}

/**
 * Sets the namespace where the controller class is
 */
PHP_METHOD(Phalcon_Dispatcher, setNamespaceName) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *namespaceName_param = NULL;
	zval namespaceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaceName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaceName_param);

	zephir_get_strval(&namespaceName, namespaceName_param);


	zephir_update_property_zval(this_ptr, SL("_namespaceName"), &namespaceName);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets a namespace to be prepended to the current handler name
 */
PHP_METHOD(Phalcon_Dispatcher, getNamespaceName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_namespaceName");

}

/**
 * Sets the default namespace
 */
PHP_METHOD(Phalcon_Dispatcher, setDefaultNamespace) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *namespaceName_param = NULL;
	zval namespaceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaceName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaceName_param);

	zephir_get_strval(&namespaceName, namespaceName_param);


	zephir_update_property_zval(this_ptr, SL("_defaultNamespace"), &namespaceName);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the default namespace
 */
PHP_METHOD(Phalcon_Dispatcher, getDefaultNamespace) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_defaultNamespace");

}

/**
 * Sets the default action name
 */
PHP_METHOD(Phalcon_Dispatcher, setDefaultAction) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *actionName_param = NULL;
	zval actionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionName_param);

	zephir_get_strval(&actionName, actionName_param);


	zephir_update_property_zval(this_ptr, SL("_defaultAction"), &actionName);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set whether the handler uses singleton mode
 */
PHP_METHOD(Phalcon_Dispatcher, setHandlerLasting) {

	zval *handlerLasting_param = NULL, __$true, __$false;
	zend_bool handlerLasting;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(1, 0, &handlerLasting_param);

	handlerLasting = zephir_get_boolval(handlerLasting_param);


	if (handlerLasting) {
		zephir_update_property_zval(this_ptr, SL("_handlerLasting"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_handlerLasting"), &__$false);
	}

}

/**
 * Gets whether the handler uses singleton mode
 */
PHP_METHOD(Phalcon_Dispatcher, getHandlerLasting) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_handlerLasting");

}

/**
 * Sets the action name to be dispatched
 */
PHP_METHOD(Phalcon_Dispatcher, setActionName) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *actionName_param = NULL;
	zval actionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionName_param);

	zephir_get_strval(&actionName, actionName_param);


	zephir_update_property_zval(this_ptr, SL("_actionName"), &actionName);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the latest dispatched action name
 */
PHP_METHOD(Phalcon_Dispatcher, getActionName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_actionName");

}

/**
 * Sets action params to be dispatched
 *
 * @param array params
 */
PHP_METHOD(Phalcon_Dispatcher, setParams) {

	zval *params, params_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &params);



	if (Z_TYPE_P(params) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_exception_ce, "Parameters must be an Array", "phalcon/dispatcher.zep", 251);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("_params"), params);

}

/**
 * Gets action params
 */
PHP_METHOD(Phalcon_Dispatcher, getParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_params");

}

/**
 * Set a param by its name or numeric index
 *
 * @param  mixed param
 * @param  mixed value
 */
PHP_METHOD(Phalcon_Dispatcher, setParam) {

	zval *param, param_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params_without_memory_grow(2, 0, &param, &value);



	zephir_update_property_array(this_ptr, SL("_params"), param, value);

}

/**
 * Gets a param by its name or numeric index
 *
 * @param  mixed param
 * @param  string|array filters
 * @param  mixed defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Dispatcher, getParam) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *param, param_sub, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, __$null, params, filter, paramValue, dependencyInjector, _2, _3, _0$$5, _1$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&paramValue);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &param, &filters, &defaultValue);

	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_OBS_VAR(&params);
	zephir_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&paramValue);
	if (!(zephir_array_isset_fetch(&paramValue, &params, param, 0))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(filters) == IS_NULL) {
		RETURN_CCTOR(&paramValue);
	}
	ZEPHIR_OBS_VAR(&dependencyInjector);
	zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_0$$5);
		ZVAL_STRING(&_0$$5, "A dependency injection object is required to access the 'filter' service");
		ZVAL_LONG(&_1$$5, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", NULL, 0, &_0$$5, &_1$$5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "filter");
	ZEPHIR_CALL_METHOD(&_2, &dependencyInjector, "getshared", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&filter, &_2);
	ZEPHIR_RETURN_CALL_METHOD(&filter, "sanitize", NULL, 0, &paramValue, filters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check if a param exists
 *
 * @param  mixed param
 * @return boolean
 */
PHP_METHOD(Phalcon_Dispatcher, hasParam) {

	zval *param, param_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(1, 0, &param);



	zephir_read_property(&_0, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, param));

}

/**
 * Returns the current method to be/executed in the dispatcher
 */
PHP_METHOD(Phalcon_Dispatcher, getActiveMethod) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("_actionName"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("_actionSuffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VV(return_value, &_0, &_1);
	return;

}

/**
 * Checks if the dispatch loop is finished or has more pendent controllers/tasks to dispatch
 */
PHP_METHOD(Phalcon_Dispatcher, isFinished) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_finished");

}

/**
 * Sets the latest returned value by an action manually
 *
 * @param mixed value
 */
PHP_METHOD(Phalcon_Dispatcher, setReturnedValue) {

	zval *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &value);



	zephir_update_property_zval(this_ptr, SL("_returnedValue"), value);

}

/**
 * Returns value returned by the latest dispatched action
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Dispatcher, getReturnedValue) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_returnedValue");

}

/**
 * Enable/Disable model binding during dispatch
 *
 * <code>
 * $di->set('dispatcher', function() {
 *     $dispatcher = new Dispatcher();
 *
 *     $dispatcher->setModelBinding(true, 'cache');
 *     return $dispatcher;
 * });
 * </code>
 *
 * @deprecated 3.1.0 Use setModelBinder method
 * @see Phalcon\Dispatcher::setModelBinder()
 */
PHP_METHOD(Phalcon_Dispatcher, setModelBinding) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, *cache = NULL, cache_sub, __$true, __$false, __$null, dependencyInjector, _0$$3, _1$$4;
	zend_bool value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cache_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value_param, &cache);

	value = zephir_get_boolval(value_param);
	if (!cache) {
		cache = &cache_sub;
		ZEPHIR_CPY_WRT(cache, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(cache);
	}


	if (Z_TYPE_P(cache) == IS_STRING) {
		ZEPHIR_OBS_VAR(&dependencyInjector);
		zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_0$$3, &dependencyInjector, "get", NULL, 0, cache);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(cache, &_0$$3);
	}
	if (value) {
		zephir_update_property_zval(this_ptr, SL("_modelBinding"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_modelBinding"), &__$false);
	}
	if (value) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_mvc_model_binder_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 67, cache);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_modelBinder"), &_1$$4);
	}
	RETURN_THIS();

}

/**
 * Enable model binding during dispatch
 *
 * <code>
 * $di->set('dispatcher', function() {
 *     $dispatcher = new Dispatcher();
 *
 *     $dispatcher->setModelBinder(new Binder(), 'cache');
 *     return $dispatcher;
 * });
 * </code>
 */
PHP_METHOD(Phalcon_Dispatcher, setModelBinder) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modelBinder, modelBinder_sub, *cache = NULL, cache_sub, __$true, __$false, __$null, dependencyInjector, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelBinder_sub);
	ZVAL_UNDEF(&cache_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &modelBinder, &cache);

	if (!cache) {
		cache = &cache_sub;
		ZEPHIR_CPY_WRT(cache, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(cache);
	}


	if (Z_TYPE_P(cache) == IS_STRING) {
		ZEPHIR_OBS_VAR(&dependencyInjector);
		zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_0$$3, &dependencyInjector, "get", NULL, 0, cache);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(cache, &_0$$3);
	}
	if (Z_TYPE_P(cache) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, modelBinder, "setcache", NULL, 0, cache);
		zephir_check_call_status();
	}
	if (1) {
		zephir_update_property_zval(this_ptr, SL("_modelBinding"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_modelBinding"), &__$false);
	}
	zephir_update_property_zval(this_ptr, SL("_modelBinder"), modelBinder);
	RETURN_THIS();

}

/**
 * Gets model binder
 */
PHP_METHOD(Phalcon_Dispatcher, getModelBinder) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_modelBinder");

}

/**
 * Process the results of the router by calling into the appropriate controller action(s)
 * including any routing data or injected parameters.
 *
 * @return object|false Returns the dispatched handler class (the Controller for Mvc dispatching or a Task
 *                      for CLI dispatching) or <tt>false</tt> if an exception occurred and the operation was
 *                      stopped by returning <tt>false</tt> in the exception handler.
 *
 * @throws \Exception if any uncaught or unhandled exception occurs during the dispatcher process.
 */
PHP_METHOD(Phalcon_Dispatcher, dispatch) {

	zval _42$$10;
	zend_bool hasService = 0, hasEventsManager = 0, _5$$5, _16$$13, _21$$15, _73$$10, _29$$18, _36$$22, _40$$24, _50$$26, _54$$32, _60$$34, _64$$37, _70$$39, _77$$44, _82$$47, _87$$49, _103$$60, _108$$63, _113$$65, _116$$68, _121$$70, _128$$74;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL, *_15 = NULL, *_20 = NULL, *_23 = NULL, *_25 = NULL, *_28 = NULL, *_30 = NULL, *_31 = NULL, *_32 = NULL, *_35 = NULL, *_39 = NULL, *_41 = NULL, *_45 = NULL, *_49 = NULL, *_53 = NULL, *_56 = NULL, *_59 = NULL, *_62 = NULL, *_66 = NULL, *_69 = NULL, *_72 = NULL, *_76 = NULL, *_81 = NULL, *_86 = NULL, *_93 = NULL, *_98 = NULL, *_102 = NULL, *_107 = NULL, *_112 = NULL, *_120 = NULL, *_124 = NULL, *_127 = NULL;
	zval __$true, __$false, value, handler, dependencyInjector, namespaceName, handlerName, actionName, params, eventsManager, actionSuffix, handlerClass, status, actionMethod, modelBinder, bindCacheKey, wasFresh, e, handlerLasting, _0, _1$$3, _2$$3, _3$$5, _4$$5, _6$$5, _7$$4, _8$$7, _9$$11, _10$$11, _13$$13, _14$$13, _17$$13, _18$$12, _19$$15, _22$$15, _24$$10, _89$$10, _100$$10, _26$$18, _27$$18, _33$$22, _34$$22, _37$$24, _38$$24, _43$$27, _44$$27, _46$$27, _47$$26, _48$$26, _51$$32, _52$$32, _55$$32, _57$$31, _58$$34, _61$$34, _63$$37, _65$$37, _67$$36, _68$$39, _71$$39, _74$$42, _75$$44, _78$$44, _79$$47, _80$$47, _83$$47, _84$$46, _85$$49, _88$$49, _90$$51, _91$$52, _92$$52, _94$$52, _95$$55, _96$$55, _97$$58, _99$$58, _101$$60, _104$$60, _105$$63, _106$$63, _109$$63, _110$$62, _111$$65, _114$$65, _115$$68, _117$$68, _118$$67, _119$$70, _122$$70, _123$$73, _125$$72, _126$$74, _129$$74, _130$$77, _131$$76, _132$$78;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberDispatches = 0;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&handlerName);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&actionSuffix);
	ZVAL_UNDEF(&handlerClass);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&actionMethod);
	ZVAL_UNDEF(&modelBinder);
	ZVAL_UNDEF(&bindCacheKey);
	ZVAL_UNDEF(&wasFresh);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&handlerLasting);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_89$$10);
	ZVAL_UNDEF(&_100$$10);
	ZVAL_UNDEF(&_26$$18);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_33$$22);
	ZVAL_UNDEF(&_34$$22);
	ZVAL_UNDEF(&_37$$24);
	ZVAL_UNDEF(&_38$$24);
	ZVAL_UNDEF(&_43$$27);
	ZVAL_UNDEF(&_44$$27);
	ZVAL_UNDEF(&_46$$27);
	ZVAL_UNDEF(&_47$$26);
	ZVAL_UNDEF(&_48$$26);
	ZVAL_UNDEF(&_51$$32);
	ZVAL_UNDEF(&_52$$32);
	ZVAL_UNDEF(&_55$$32);
	ZVAL_UNDEF(&_57$$31);
	ZVAL_UNDEF(&_58$$34);
	ZVAL_UNDEF(&_61$$34);
	ZVAL_UNDEF(&_63$$37);
	ZVAL_UNDEF(&_65$$37);
	ZVAL_UNDEF(&_67$$36);
	ZVAL_UNDEF(&_68$$39);
	ZVAL_UNDEF(&_71$$39);
	ZVAL_UNDEF(&_74$$42);
	ZVAL_UNDEF(&_75$$44);
	ZVAL_UNDEF(&_78$$44);
	ZVAL_UNDEF(&_79$$47);
	ZVAL_UNDEF(&_80$$47);
	ZVAL_UNDEF(&_83$$47);
	ZVAL_UNDEF(&_84$$46);
	ZVAL_UNDEF(&_85$$49);
	ZVAL_UNDEF(&_88$$49);
	ZVAL_UNDEF(&_90$$51);
	ZVAL_UNDEF(&_91$$52);
	ZVAL_UNDEF(&_92$$52);
	ZVAL_UNDEF(&_94$$52);
	ZVAL_UNDEF(&_95$$55);
	ZVAL_UNDEF(&_96$$55);
	ZVAL_UNDEF(&_97$$58);
	ZVAL_UNDEF(&_99$$58);
	ZVAL_UNDEF(&_101$$60);
	ZVAL_UNDEF(&_104$$60);
	ZVAL_UNDEF(&_105$$63);
	ZVAL_UNDEF(&_106$$63);
	ZVAL_UNDEF(&_109$$63);
	ZVAL_UNDEF(&_110$$62);
	ZVAL_UNDEF(&_111$$65);
	ZVAL_UNDEF(&_114$$65);
	ZVAL_UNDEF(&_115$$68);
	ZVAL_UNDEF(&_117$$68);
	ZVAL_UNDEF(&_118$$67);
	ZVAL_UNDEF(&_119$$70);
	ZVAL_UNDEF(&_122$$70);
	ZVAL_UNDEF(&_123$$73);
	ZVAL_UNDEF(&_125$$72);
	ZVAL_UNDEF(&_126$$74);
	ZVAL_UNDEF(&_129$$74);
	ZVAL_UNDEF(&_130$$77);
	ZVAL_UNDEF(&_131$$76);
	ZVAL_UNDEF(&_132$$78);
	ZVAL_UNDEF(&_42$$10);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dependencyInjector, &_0);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "A dependency injection container is required to access related dispatching services");
		ZVAL_LONG(&_2$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", NULL, 0, &_1$$3, &_2$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_0, this_ptr, SL("_eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	hasEventsManager = Z_TYPE_P(&eventsManager) == IS_OBJECT;
	if (1) {
		zephir_update_property_zval(this_ptr, SL("_finished"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_finished"), &__$false);
	}
	if (hasEventsManager) {

		/* try_start_1: */

			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "dispatch:beforeDispatchLoop");
			ZEPHIR_CALL_METHOD(&_3$$5, &eventsManager, "fire", NULL, 0, &_4$$5, this_ptr);
			zephir_check_call_status_or_jump(try_end_1);
			_5$$5 = ZEPHIR_IS_FALSE_IDENTICAL(&_3$$5);
			if (_5$$5) {
				zephir_read_property(&_6$$5, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				_5$$5 = !ZEPHIR_IS_FALSE_IDENTICAL(&_6$$5);
			}
			if (_5$$5) {
				RETURN_MM_BOOL(0);
			}

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_7$$4);
			ZVAL_OBJ(&_7$$4, EG(exception));
			Z_ADDREF_P(&_7$$4);
			if (zephir_instance_of_ev(&_7$$4, zend_exception_get_default(TSRMLS_C))) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e, &_7$$4);
				ZEPHIR_CALL_METHOD(&status, this_ptr, "_handleexception", NULL, 0, &e);
				zephir_check_call_status();
				zephir_read_property(&_8$$7, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&_8$$7)) {
					if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
						RETURN_MM_BOOL(0);
					}
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 479);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	ZEPHIR_INIT_VAR(&value);
	ZVAL_NULL(&value);
	ZEPHIR_INIT_VAR(&handler);
	ZVAL_NULL(&handler);
	numberDispatches = 0;
	ZEPHIR_OBS_VAR(&actionSuffix);
	zephir_read_property(&actionSuffix, this_ptr, SL("_actionSuffix"), PH_NOISY_CC);
	if (0) {
		zephir_update_property_zval(this_ptr, SL("_finished"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_finished"), &__$false);
	}
	while (1) {
		zephir_read_property(&_0, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
		if (!(!(zephir_is_true(&_0)))) {
			break;
		}
		numberDispatches++;
		if (numberDispatches == 256) {
			ZEPHIR_INIT_NVAR(&_9$$11);
			ZVAL_STRING(&_9$$11, "Dispatcher has detected a cyclic routing causing stability problems");
			ZVAL_LONG(&_10$$11, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_throwdispatchexception", &_11, 0, &_9$$11, &_10$$11);
			zephir_check_call_status();
			break;
		}
		if (1) {
			zephir_update_property_zval(this_ptr, SL("_finished"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_finished"), &__$false);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_resolveemptyproperties", &_12, 0);
		zephir_check_call_status();
		if (hasEventsManager) {

			/* try_start_2: */

				ZEPHIR_INIT_NVAR(&_14$$13);
				ZVAL_STRING(&_14$$13, "dispatch:beforeDispatch");
				ZEPHIR_CALL_METHOD(&_13$$13, &eventsManager, "fire", &_15, 0, &_14$$13, this_ptr);
				zephir_check_call_status_or_jump(try_end_2);
				_16$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&_13$$13);
				if (!(_16$$13)) {
					zephir_read_property(&_17$$13, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
					_16$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&_17$$13);
				}
				if (_16$$13) {
					continue;
				}

			try_end_2:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_18$$12);
				ZVAL_OBJ(&_18$$12, EG(exception));
				Z_ADDREF_P(&_18$$12);
				if (zephir_instance_of_ev(&_18$$12, zend_exception_get_default(TSRMLS_C))) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&e, &_18$$12);
					ZEPHIR_CALL_METHOD(&_19$$15, this_ptr, "_handleexception", &_20, 0, &e);
					zephir_check_call_status();
					_21$$15 = ZEPHIR_IS_FALSE_IDENTICAL(&_19$$15);
					if (!(_21$$15)) {
						zephir_read_property(&_22$$15, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
						_21$$15 = ZEPHIR_IS_FALSE_IDENTICAL(&_22$$15);
					}
					if (_21$$15) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 515);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		ZEPHIR_CALL_METHOD(&handlerClass, this_ptr, "gethandlerclass", &_23, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_24$$10, &dependencyInjector, "has", &_25, 0, &handlerClass);
		zephir_check_call_status();
		hasService = zephir_get_boolval(&_24$$10);
		if (!(hasService)) {
			hasService = zephir_class_exists(&handlerClass, 1);
		}
		if (!(hasService)) {
			ZEPHIR_INIT_NVAR(&_26$$18);
			ZEPHIR_CONCAT_VS(&_26$$18, &handlerClass, " handler class cannot be loaded");
			ZVAL_LONG(&_27$$18, 2);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_28, 0, &_26$$18, &_27$$18);
			zephir_check_call_status();
			_29$$18 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_29$$18) {
				zephir_read_property(&_27$$18, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				_29$$18 = ZEPHIR_IS_FALSE_IDENTICAL(&_27$$18);
			}
			if (_29$$18) {
				continue;
			}
			break;
		}
		ZEPHIR_OBS_NVAR(&handlerLasting);
		zephir_read_property(&handlerLasting, this_ptr, SL("_handlerLasting"), PH_NOISY_CC);
		if (zephir_is_true(&handlerLasting)) {
			ZEPHIR_CALL_METHOD(&handler, &dependencyInjector, "getshared", &_30, 0, &handlerClass);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&handler, &dependencyInjector, "get", &_31, 0, &handlerClass);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&wasFresh, &dependencyInjector, "wasfreshinstance", &_32, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&handler) != IS_OBJECT) {
			ZEPHIR_INIT_NVAR(&_33$$22);
			ZVAL_STRING(&_33$$22, "Invalid handler returned from the services container");
			ZVAL_LONG(&_34$$22, 3);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_35, 0, &_33$$22, &_34$$22);
			zephir_check_call_status();
			_36$$22 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_36$$22) {
				zephir_read_property(&_34$$22, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				_36$$22 = ZEPHIR_IS_FALSE_IDENTICAL(&_34$$22);
			}
			if (_36$$22) {
				continue;
			}
			break;
		}
		zephir_update_property_zval(this_ptr, SL("_activeHandler"), &handler);
		ZEPHIR_OBS_NVAR(&namespaceName);
		zephir_read_property(&namespaceName, this_ptr, SL("_namespaceName"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&handlerName);
		zephir_read_property(&handlerName, this_ptr, SL("_handlerName"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&actionName);
		zephir_read_property(&actionName, this_ptr, SL("_actionName"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&params);
		zephir_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
		if (Z_TYPE_P(&params) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&_37$$24);
			ZVAL_STRING(&_37$$24, "Action parameters must be an Array");
			ZVAL_LONG(&_38$$24, 4);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_39, 0, &_37$$24, &_38$$24);
			zephir_check_call_status();
			_40$$24 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_40$$24) {
				zephir_read_property(&_38$$24, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				_40$$24 = ZEPHIR_IS_FALSE_IDENTICAL(&_38$$24);
			}
			if (_40$$24) {
				continue;
			}
			break;
		}
		ZEPHIR_CALL_METHOD(&actionMethod, this_ptr, "getactivemethod", &_41, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_42$$10);
		zephir_create_array(&_42$$10, 2, 0);
		zephir_array_fast_append(&_42$$10, &handler);
		zephir_array_fast_append(&_42$$10, &actionMethod);
		if (!(zephir_is_callable(&_42$$10))) {
			if (hasEventsManager) {
				ZEPHIR_INIT_NVAR(&_44$$27);
				ZVAL_STRING(&_44$$27, "dispatch:beforeNotFoundAction");
				ZEPHIR_CALL_METHOD(&_43$$27, &eventsManager, "fire", &_45, 0, &_44$$27, this_ptr);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_43$$27)) {
					continue;
				}
				zephir_read_property(&_46$$27, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_46$$27)) {
					continue;
				}
			}
			ZEPHIR_INIT_NVAR(&_47$$26);
			ZEPHIR_CONCAT_SVSVS(&_47$$26, "Action '", &actionName, "' was not found on handler '", &handlerName, "'");
			ZVAL_LONG(&_48$$26, 5);
			ZEPHIR_CALL_METHOD(&status, this_ptr, "_throwdispatchexception", &_49, 0, &_47$$26, &_48$$26);
			zephir_check_call_status();
			_50$$26 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
			if (_50$$26) {
				zephir_read_property(&_48$$26, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
				_50$$26 = ZEPHIR_IS_FALSE_IDENTICAL(&_48$$26);
			}
			if (_50$$26) {
				continue;
			}
			break;
		}
		if (hasEventsManager) {

			/* try_start_3: */

				ZEPHIR_INIT_NVAR(&_52$$32);
				ZVAL_STRING(&_52$$32, "dispatch:beforeExecuteRoute");
				ZEPHIR_CALL_METHOD(&_51$$32, &eventsManager, "fire", &_53, 0, &_52$$32, this_ptr);
				zephir_check_call_status_or_jump(try_end_3);
				_54$$32 = ZEPHIR_IS_FALSE_IDENTICAL(&_51$$32);
				if (!(_54$$32)) {
					zephir_read_property(&_55$$32, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
					_54$$32 = ZEPHIR_IS_FALSE_IDENTICAL(&_55$$32);
				}
				if (_54$$32) {
					ZEPHIR_CALL_METHOD(NULL, &dependencyInjector, "remove", &_56, 0, &handlerClass);
					zephir_check_call_status_or_jump(try_end_3);
					continue;
				}

			try_end_3:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_57$$31);
				ZVAL_OBJ(&_57$$31, EG(exception));
				Z_ADDREF_P(&_57$$31);
				if (zephir_instance_of_ev(&_57$$31, zend_exception_get_default(TSRMLS_C))) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&e, &_57$$31);
					ZEPHIR_CALL_METHOD(&_58$$34, this_ptr, "_handleexception", &_59, 0, &e);
					zephir_check_call_status();
					_60$$34 = ZEPHIR_IS_FALSE_IDENTICAL(&_58$$34);
					if (!(_60$$34)) {
						zephir_read_property(&_61$$34, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
						_60$$34 = ZEPHIR_IS_FALSE_IDENTICAL(&_61$$34);
					}
					if (_60$$34) {
						ZEPHIR_CALL_METHOD(NULL, &dependencyInjector, "remove", &_62, 0, &handlerClass);
						zephir_check_call_status();
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 616);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if ((zephir_method_exists_ex(&handler, ZEND_STRL("beforeexecuteroute")) == SUCCESS)) {

			/* try_start_4: */

				ZEPHIR_CALL_METHOD(&_63$$37, &handler, "beforeexecuteroute", NULL, 0, this_ptr);
				zephir_check_call_status_or_jump(try_end_4);
				_64$$37 = ZEPHIR_IS_FALSE_IDENTICAL(&_63$$37);
				if (!(_64$$37)) {
					zephir_read_property(&_65$$37, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
					_64$$37 = ZEPHIR_IS_FALSE_IDENTICAL(&_65$$37);
				}
				if (_64$$37) {
					ZEPHIR_CALL_METHOD(NULL, &dependencyInjector, "remove", &_66, 0, &handlerClass);
					zephir_check_call_status_or_jump(try_end_4);
					continue;
				}

			try_end_4:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_67$$36);
				ZVAL_OBJ(&_67$$36, EG(exception));
				Z_ADDREF_P(&_67$$36);
				if (zephir_instance_of_ev(&_67$$36, zend_exception_get_default(TSRMLS_C))) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&e, &_67$$36);
					ZEPHIR_CALL_METHOD(&_68$$39, this_ptr, "_handleexception", &_69, 0, &e);
					zephir_check_call_status();
					_70$$39 = ZEPHIR_IS_FALSE_IDENTICAL(&_68$$39);
					if (!(_70$$39)) {
						zephir_read_property(&_71$$39, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
						_70$$39 = ZEPHIR_IS_FALSE_IDENTICAL(&_71$$39);
					}
					if (_70$$39) {
						ZEPHIR_CALL_METHOD(NULL, &dependencyInjector, "remove", &_72, 0, &handlerClass);
						zephir_check_call_status();
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 633);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		_73$$10 = ZEPHIR_IS_TRUE_IDENTICAL(&wasFresh);
		if (!(_73$$10)) {
			_73$$10 = !zephir_is_true(&handlerLasting);
		}
		if (_73$$10) {
			if ((zephir_method_exists_ex(&handler, ZEND_STRL("initialize")) == SUCCESS)) {

				/* try_start_5: */

					if (1) {
						zephir_update_property_zval(this_ptr, SL("_isControllerInitialize"), &__$true);
					} else {
						zephir_update_property_zval(this_ptr, SL("_isControllerInitialize"), &__$false);
					}
					ZEPHIR_CALL_METHOD(NULL, &handler, "initialize", NULL, 0);
					zephir_check_call_status_or_jump(try_end_5);

				try_end_5:

				if (EG(exception)) {
					ZEPHIR_INIT_NVAR(&_74$$42);
					ZVAL_OBJ(&_74$$42, EG(exception));
					Z_ADDREF_P(&_74$$42);
					if (zephir_instance_of_ev(&_74$$42, zend_exception_get_default(TSRMLS_C))) {
						zend_clear_exception(TSRMLS_C);
						ZEPHIR_CPY_WRT(&e, &_74$$42);
						if (0) {
							zephir_update_property_zval(this_ptr, SL("_isControllerInitialize"), &__$true);
						} else {
							zephir_update_property_zval(this_ptr, SL("_isControllerInitialize"), &__$false);
						}
						ZEPHIR_CALL_METHOD(&_75$$44, this_ptr, "_handleexception", &_76, 0, &e);
						zephir_check_call_status();
						_77$$44 = ZEPHIR_IS_FALSE_IDENTICAL(&_75$$44);
						if (!(_77$$44)) {
							zephir_read_property(&_78$$44, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
							_77$$44 = ZEPHIR_IS_FALSE_IDENTICAL(&_78$$44);
						}
						if (_77$$44) {
							continue;
						}
						zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 666);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
			if (0) {
				zephir_update_property_zval(this_ptr, SL("_isControllerInitialize"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, SL("_isControllerInitialize"), &__$false);
			}
			if (zephir_is_true(&eventsManager)) {

				/* try_start_6: */

					ZEPHIR_INIT_NVAR(&_80$$47);
					ZVAL_STRING(&_80$$47, "dispatch:afterInitialize");
					ZEPHIR_CALL_METHOD(&_79$$47, &eventsManager, "fire", &_81, 0, &_80$$47, this_ptr);
					zephir_check_call_status_or_jump(try_end_6);
					_82$$47 = ZEPHIR_IS_FALSE_IDENTICAL(&_79$$47);
					if (!(_82$$47)) {
						zephir_read_property(&_83$$47, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
						_82$$47 = ZEPHIR_IS_FALSE_IDENTICAL(&_83$$47);
					}
					if (_82$$47) {
						continue;
					}

				try_end_6:

				if (EG(exception)) {
					ZEPHIR_INIT_NVAR(&_84$$46);
					ZVAL_OBJ(&_84$$46, EG(exception));
					Z_ADDREF_P(&_84$$46);
					if (zephir_instance_of_ev(&_84$$46, zend_exception_get_default(TSRMLS_C))) {
						zend_clear_exception(TSRMLS_C);
						ZEPHIR_CPY_WRT(&e, &_84$$46);
						ZEPHIR_CALL_METHOD(&_85$$49, this_ptr, "_handleexception", &_86, 0, &e);
						zephir_check_call_status();
						_87$$49 = ZEPHIR_IS_FALSE_IDENTICAL(&_85$$49);
						if (!(_87$$49)) {
							zephir_read_property(&_88$$49, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
							_87$$49 = ZEPHIR_IS_FALSE_IDENTICAL(&_88$$49);
						}
						if (_87$$49) {
							continue;
						}
						zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 683);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		}
		zephir_read_property(&_89$$10, this_ptr, SL("_modelBinding"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_89$$10)) {
			ZEPHIR_OBS_NVAR(&modelBinder);
			zephir_read_property(&modelBinder, this_ptr, SL("_modelBinder"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(&bindCacheKey);
			ZEPHIR_CONCAT_SVSV(&bindCacheKey, "_PHMB_", &handlerClass, "_", &actionMethod);
			ZEPHIR_CALL_METHOD(&_90$$51, &modelBinder, "bindtohandler", NULL, 0, &handler, &params, &bindCacheKey, &actionMethod);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&params, &_90$$51);
		}
		if (hasEventsManager) {
			ZEPHIR_INIT_NVAR(&_92$$52);
			ZVAL_STRING(&_92$$52, "dispatch:afterBinding");
			ZEPHIR_CALL_METHOD(&_91$$52, &eventsManager, "fire", &_93, 0, &_92$$52, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_91$$52)) {
				continue;
			}
			zephir_read_property(&_94$$52, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_94$$52)) {
				continue;
			}
		}
		if ((zephir_method_exists_ex(&handler, ZEND_STRL("afterbinding")) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&_95$$55, &handler, "afterbinding", NULL, 0, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_95$$55)) {
				continue;
			}
			zephir_read_property(&_96$$55, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_96$$55)) {
				continue;
			}
		}
		zephir_update_property_zval(this_ptr, SL("_lastHandler"), &handler);

		/* try_start_7: */

			ZEPHIR_CALL_METHOD(&_97$$58, this_ptr, "callactionmethod", &_98, 0, &handler, &actionMethod, &params);
			zephir_check_call_status_or_jump(try_end_7);
			zephir_update_property_zval(this_ptr, SL("_returnedValue"), &_97$$58);
			zephir_read_property(&_99$$58, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_99$$58)) {
				continue;
			}

		try_end_7:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_100$$10);
			ZVAL_OBJ(&_100$$10, EG(exception));
			Z_ADDREF_P(&_100$$10);
			if (zephir_instance_of_ev(&_100$$10, zend_exception_get_default(TSRMLS_C))) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e, &_100$$10);
				ZEPHIR_CALL_METHOD(&_101$$60, this_ptr, "_handleexception", &_102, 0, &e);
				zephir_check_call_status();
				_103$$60 = ZEPHIR_IS_FALSE_IDENTICAL(&_101$$60);
				if (!(_103$$60)) {
					zephir_read_property(&_104$$60, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
					_103$$60 = ZEPHIR_IS_FALSE_IDENTICAL(&_104$$60);
				}
				if (_103$$60) {
					continue;
				}
				zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 733);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (hasEventsManager) {

			/* try_start_8: */

				ZEPHIR_INIT_NVAR(&_106$$63);
				ZVAL_STRING(&_106$$63, "dispatch:afterExecuteRoute");
				ZEPHIR_CALL_METHOD(&_105$$63, &eventsManager, "fire", &_107, 0, &_106$$63, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_8);
				_108$$63 = ZEPHIR_IS_FALSE_IDENTICAL(&_105$$63);
				if (!(_108$$63)) {
					zephir_read_property(&_109$$63, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
					_108$$63 = ZEPHIR_IS_FALSE_IDENTICAL(&_109$$63);
				}
				if (_108$$63) {
					continue;
				}

			try_end_8:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_110$$62);
				ZVAL_OBJ(&_110$$62, EG(exception));
				Z_ADDREF_P(&_110$$62);
				if (zephir_instance_of_ev(&_110$$62, zend_exception_get_default(TSRMLS_C))) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&e, &_110$$62);
					ZEPHIR_CALL_METHOD(&_111$$65, this_ptr, "_handleexception", &_112, 0, &e);
					zephir_check_call_status();
					_113$$65 = ZEPHIR_IS_FALSE_IDENTICAL(&_111$$65);
					if (!(_113$$65)) {
						zephir_read_property(&_114$$65, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
						_113$$65 = ZEPHIR_IS_FALSE_IDENTICAL(&_114$$65);
					}
					if (_113$$65) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 747);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if ((zephir_method_exists_ex(&handler, ZEND_STRL("afterexecuteroute")) == SUCCESS)) {

			/* try_start_9: */

				ZEPHIR_CALL_METHOD(&_115$$68, &handler, "afterexecuteroute", NULL, 0, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_9);
				_116$$68 = ZEPHIR_IS_FALSE_IDENTICAL(&_115$$68);
				if (!(_116$$68)) {
					zephir_read_property(&_117$$68, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
					_116$$68 = ZEPHIR_IS_FALSE_IDENTICAL(&_117$$68);
				}
				if (_116$$68) {
					continue;
				}

			try_end_9:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_118$$67);
				ZVAL_OBJ(&_118$$67, EG(exception));
				Z_ADDREF_P(&_118$$67);
				if (zephir_instance_of_ev(&_118$$67, zend_exception_get_default(TSRMLS_C))) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&e, &_118$$67);
					ZEPHIR_CALL_METHOD(&_119$$70, this_ptr, "_handleexception", &_120, 0, &e);
					zephir_check_call_status();
					_121$$70 = ZEPHIR_IS_FALSE_IDENTICAL(&_119$$70);
					if (!(_121$$70)) {
						zephir_read_property(&_122$$70, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
						_121$$70 = ZEPHIR_IS_FALSE_IDENTICAL(&_122$$70);
					}
					if (_121$$70) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 762);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		if (hasEventsManager) {

			/* try_start_10: */

				ZEPHIR_INIT_NVAR(&_123$$73);
				ZVAL_STRING(&_123$$73, "dispatch:afterDispatch");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_124, 0, &_123$$73, this_ptr, &value);
				zephir_check_call_status_or_jump(try_end_10);

			try_end_10:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_125$$72);
				ZVAL_OBJ(&_125$$72, EG(exception));
				Z_ADDREF_P(&_125$$72);
				if (zephir_instance_of_ev(&_125$$72, zend_exception_get_default(TSRMLS_C))) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&e, &_125$$72);
					ZEPHIR_CALL_METHOD(&_126$$74, this_ptr, "_handleexception", &_127, 0, &e);
					zephir_check_call_status();
					_128$$74 = ZEPHIR_IS_FALSE_IDENTICAL(&_126$$74);
					if (!(_128$$74)) {
						zephir_read_property(&_129$$74, this_ptr, SL("_finished"), PH_NOISY_CC | PH_READONLY);
						_128$$74 = ZEPHIR_IS_FALSE_IDENTICAL(&_129$$74);
					}
					if (_128$$74) {
						continue;
					}
					zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 776);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	if (hasEventsManager) {

		/* try_start_11: */

			ZEPHIR_INIT_VAR(&_130$$77);
			ZVAL_STRING(&_130$$77, "dispatch:afterDispatchLoop");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_130$$77, this_ptr);
			zephir_check_call_status_or_jump(try_end_11);

		try_end_11:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_131$$76);
			ZVAL_OBJ(&_131$$76, EG(exception));
			Z_ADDREF_P(&_131$$76);
			if (zephir_instance_of_ev(&_131$$76, zend_exception_get_default(TSRMLS_C))) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e, &_131$$76);
				ZEPHIR_CALL_METHOD(&_132$$78, this_ptr, "_handleexception", NULL, 0, &e);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_132$$78)) {
					RETURN_MM_BOOL(0);
				}
				zephir_throw_exception_debug(&e, "phalcon/dispatcher.zep", 793);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	RETURN_CCTOR(&handler);

}

/**
 * Forwards the execution flow to another controller/action.
 *
 * <code>
 * $this->dispatcher->forward(
 *     [
 *         "controller" => "posts",
 *         "action"     => "index",
 *     ]
 * );
 * </code>
 *
 * @param array forward
 *
 * @throws \Phalcon\Exception
 */
PHP_METHOD(Phalcon_Dispatcher, forward) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *forward, forward_sub, __$true, __$false, namespaceName, controllerName, params, actionName, taskName, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&forward_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&controllerName);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&taskName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &forward);



	zephir_read_property(&_0, this_ptr, SL("_isControllerInitialize"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_exception_ce, "Forwarding inside a controller's initialize() method is forbidden", "phalcon/dispatcher.zep", 824);
		return;
	}
	if (Z_TYPE_P(forward) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_exception_ce, "Forward parameter must be an Array", "phalcon/dispatcher.zep", 832);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("_namespaceName"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("_previousNamespaceName"), &_1);
	zephir_read_property(&_2, this_ptr, SL("_handlerName"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("_previousHandlerName"), &_2);
	zephir_read_property(&_3, this_ptr, SL("_actionName"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("_previousActionName"), &_3);
	if (zephir_array_isset_string_fetch(&namespaceName, forward, SL("namespace"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_namespaceName"), &namespaceName);
	}
	ZEPHIR_OBS_VAR(&taskName);
	if (zephir_array_isset_string_fetch(&controllerName, forward, SL("controller"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_handlerName"), &controllerName);
	} else if (zephir_array_isset_string_fetch(&taskName, forward, SL("task"), 0)) {
		zephir_update_property_zval(this_ptr, SL("_handlerName"), &taskName);
	}
	if (zephir_array_isset_string_fetch(&actionName, forward, SL("action"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_actionName"), &actionName);
	}
	if (zephir_array_isset_string_fetch(&params, forward, SL("params"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_params"), &params);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, SL("_finished"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_finished"), &__$false);
	}
	if (1) {
		zephir_update_property_zval(this_ptr, SL("_forwarded"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_forwarded"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check if the current executed action was forwarded by another one
 */
PHP_METHOD(Phalcon_Dispatcher, wasForwarded) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_forwarded");

}

/**
 * Possible class name that will be located to dispatch the request
 */
PHP_METHOD(Phalcon_Dispatcher, getHandlerClass) {

	zval handlerSuffix, handlerName, namespaceName, camelizedClass, handlerClass;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handlerSuffix);
	ZVAL_UNDEF(&handlerName);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&camelizedClass);
	ZVAL_UNDEF(&handlerClass);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_resolveemptyproperties", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&handlerSuffix);
	zephir_read_property(&handlerSuffix, this_ptr, SL("_handlerSuffix"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&handlerName);
	zephir_read_property(&handlerName, this_ptr, SL("_handlerName"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&namespaceName);
	zephir_read_property(&namespaceName, this_ptr, SL("_namespaceName"), PH_NOISY_CC);
	if (!(zephir_memnstr_str(&handlerName, SL("\\"), "phalcon/dispatcher.zep", 889))) {
		ZEPHIR_INIT_VAR(&camelizedClass);
		zephir_camelize(&camelizedClass, &handlerName, NULL  );
	} else {
		ZEPHIR_CPY_WRT(&camelizedClass, &handlerName);
	}
	if (zephir_is_true(&namespaceName)) {
		ZEPHIR_INIT_VAR(&handlerClass);
		if (zephir_end_with_str(&namespaceName, SL("\\"))) {
			ZEPHIR_CONCAT_VVV(&handlerClass, &namespaceName, &camelizedClass, &handlerSuffix);
		} else {
			ZEPHIR_CONCAT_VSVV(&handlerClass, &namespaceName, "\\", &camelizedClass, &handlerSuffix);
		}
	} else {
		ZEPHIR_INIT_NVAR(&handlerClass);
		ZEPHIR_CONCAT_VV(&handlerClass, &camelizedClass, &handlerSuffix);
	}
	RETURN_CCTOR(&handlerClass);

}

PHP_METHOD(Phalcon_Dispatcher, callActionMethod) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params, _0;
	zval actionMethod;
	zval *handler, handler_sub, *actionMethod_param = NULL, *params_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&actionMethod);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &handler, &actionMethod_param, &params_param);

	zephir_get_strval(&actionMethod, actionMethod_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, handler);
	zephir_array_fast_append(&_0, &actionMethod);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &params);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns bound models from binder instance
 *
 * <code>
 * class UserController extends Controller
 * {
 *     public function showAction(User $user)
 *     {
 *         $boundModels = $this->dispatcher->getBoundModels(); // return array with $user
 *     }
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Dispatcher, getBoundModels) {

	zval modelBinder;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelBinder);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&modelBinder);
	zephir_read_property(&modelBinder, this_ptr, SL("_modelBinder"), PH_NOISY_CC);
	if (Z_TYPE_P(&modelBinder) != IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(&modelBinder, "getboundmodels", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Set empty properties to their defaults (where defaults are available)
 */
PHP_METHOD(Phalcon_Dispatcher, _resolveEmptyProperties) {

	zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);


	zephir_read_property(&_0, this_ptr, SL("_namespaceName"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		zephir_read_property(&_1$$3, this_ptr, SL("_defaultNamespace"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("_namespaceName"), &_1$$3);
	}
	zephir_read_property(&_2, this_ptr, SL("_handlerName"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_2))) {
		zephir_read_property(&_3$$4, this_ptr, SL("_defaultHandler"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("_handlerName"), &_3$$4);
	}
	zephir_read_property(&_4, this_ptr, SL("_actionName"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_4))) {
		zephir_read_property(&_5$$5, this_ptr, SL("_defaultAction"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("_actionName"), &_5$$5);
	}

}

zend_object *zephir_init_properties_Phalcon_Dispatcher(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_params"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

