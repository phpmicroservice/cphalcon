
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/**
 * Phalcon\Acl\Adapter\Memory
 *
 * Manages ACL lists in memory
 *
 *<code>
 * $acl = new \Phalcon\Acl\Adapter\Memory();
 *
 * $acl->setDefaultAction(
 *     \Phalcon\Acl::DENY
 * );
 *
 * // Register roles
 * $roles = [
 *     "users"  => new \Phalcon\Acl\Role("Users"),
 *     "guests" => new \Phalcon\Acl\Role("Guests"),
 * ];
 * foreach ($roles as $role) {
 *     $acl->addRole($role);
 * }
 *
 * // Private area resources
 * $privateResources = [
 *     "companies" => ["index", "search", "new", "edit", "save", "create", "delete"],
 *     "products"  => ["index", "search", "new", "edit", "save", "create", "delete"],
 *     "invoices"  => ["index", "profile"],
 * ];
 *
 * foreach ($privateResources as $resourceName => $actions) {
 *     $acl->addResource(
 *         new \Phalcon\Acl\Resource($resourceName),
 *         $actions
 *     );
 * }
 *
 * // Public area resources
 * $publicResources = [
 *     "index"   => ["index"],
 *     "about"   => ["index"],
 *     "session" => ["index", "register", "start", "end"],
 *     "contact" => ["index", "send"],
 * ];
 *
 * foreach ($publicResources as $resourceName => $actions) {
 *     $acl->addResource(
 *         new \Phalcon\Acl\Resource($resourceName),
 *         $actions
 *     );
 * }
 *
 * // Grant access to public areas to both users and guests
 * foreach ($roles as $role){
 *     foreach ($publicResources as $resource => $actions) {
 *         $acl->allow($role->getName(), $resource, "*");
 *     }
 * }
 *
 * // Grant access to private area to role Users
 * foreach ($privateResources as $resource => $actions) {
 *     foreach ($actions as $action) {
 *         $acl->allow("Users", $resource, $action);
 *     }
 * }
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter_Memory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Acl\\Adapter, Memory, phalcon, acl_adapter_memory, phalcon_acl_adapter_ce, phalcon_acl_adapter_memory_method_entry, 0);

	/**
	 * Roles Names
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_rolesNames"), ZEND_ACC_PROTECTED);

	/**
	 * Roles
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_roles"), ZEND_ACC_PROTECTED);

	/**
	 * Resource Names
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_resourcesNames"), ZEND_ACC_PROTECTED);

	/**
	 * Resources
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_resources"), ZEND_ACC_PROTECTED);

	/**
	 * Access
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_access"), ZEND_ACC_PROTECTED);

	/**
	 * Role Inherits
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_roleInherits"), ZEND_ACC_PROTECTED);

	/**
	 * Access List
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_accessList"), ZEND_ACC_PROTECTED);

	/**
	 * Function List
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_func"), ZEND_ACC_PROTECTED);

	/**
	 * Default action for no arguments is allow
	 *
	 * @var mixed
	 */
	zend_declare_property_long(phalcon_acl_adapter_memory_ce, SL("_noArgumentsDefaultAction"), 1, ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Phalcon\Acl\Adapter\Memory constructor
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, __construct) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	zephir_array_update_string(&_0, SL("*"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("_resourcesNames"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0);
	zephir_array_update_string(&_1, SL("*!*"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("_accessList"), &_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a role to the ACL list. Second parameter allows inheriting access data from other existing role
 *
 * Example:
 * <code>
 * $acl->addRole(
 *     new Phalcon\Acl\Role("administrator"),
 *     "consultant"
 * );
 *
 * $acl->addRole("administrator", "consultant");
 * </code>
 *
 * @param  array|string         accessInherits
 * @param  RoleInterface|string role
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addRole) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *role, role_sub, *accessInherits = NULL, accessInherits_sub, __$true, __$null, roleName, roleObject, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&role_sub);
	ZVAL_UNDEF(&accessInherits_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&roleObject);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &role, &accessInherits);

	if (!accessInherits) {
		accessInherits = &accessInherits_sub;
		accessInherits = &__$null;
	}


	_0 = Z_TYPE_P(role) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(role, phalcon_acl_roleinterface_ce);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&roleName, role, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&roleObject, role);
	} else if (Z_TYPE_P(role) == IS_STRING) {
		ZEPHIR_CPY_WRT(&roleName, role);
		ZEPHIR_INIT_NVAR(&roleObject);
		object_init_ex(&roleObject, phalcon_acl_role_ce);
		ZEPHIR_CALL_METHOD(NULL, &roleObject, "__construct", NULL, 75, role);
		zephir_check_call_status();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Role must be either an string or implement RoleInterface", "phalcon/acl/adapter/memory.zep", 201);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("_rolesNames"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &roleName)) {
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_array_append(this_ptr, SL("_roles"), &roleObject);
	zephir_update_property_array(this_ptr, SL("_rolesNames"), &roleName, &__$true);
	if (Z_TYPE_P(accessInherits) != IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addinherit", NULL, 0, &roleName, accessInherits);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Do a role inherit from another existing role
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit) {

	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *roleToInherit, roleToInherit_sub, __$true, roleInheritName, rolesNames, deepInheritName, _3, _11, _0$$3, _4$$6, _5$$6, *_6$$6, _7$$6, _9$$9, _10$$9;
	zval roleName, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&roleToInherit_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&roleInheritName);
	ZVAL_UNDEF(&rolesNames);
	ZVAL_UNDEF(&deepInheritName);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &roleName_param, &roleToInherit);

	zephir_get_strval(&roleName, roleName_param);


	ZEPHIR_OBS_VAR(&rolesNames);
	zephir_read_property(&rolesNames, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(&rolesNames, &roleName))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SVS(&_1$$3, "Role '", &roleName, "' does not exist in the role list");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 4, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/acl/adapter/memory.zep", 227);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = Z_TYPE_P(roleToInherit) == IS_OBJECT;
	if (_2) {
		_2 = zephir_instance_of_ev(roleToInherit, phalcon_acl_roleinterface_ce);
	}
	if (_2) {
		ZEPHIR_CALL_METHOD(&roleInheritName, roleToInherit, "getname", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&roleInheritName, roleToInherit);
	}
	zephir_read_property(&_3, this_ptr, SL("_roleInherits"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_3, &roleInheritName)) {
		zephir_read_property(&_4$$6, this_ptr, SL("_roleInherits"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_5$$6, &_4$$6, &roleInheritName, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 240);
		zephir_is_iterable(&_5$$6, 0, "phalcon/acl/adapter/memory.zep", 243);
		if (Z_TYPE_P(&_5$$6) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_5$$6), _6$$6)
			{
				ZEPHIR_INIT_NVAR(&deepInheritName);
				ZVAL_COPY(&deepInheritName, _6$$6);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addinherit", &_8, 76, &roleName, &deepInheritName);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_5$$6, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_7$$6, &_5$$6, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_7$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&deepInheritName, &_5$$6, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "addinherit", &_8, 76, &roleName, &deepInheritName);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_5$$6, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&deepInheritName);
	}
	if (!(zephir_array_isset(&rolesNames, &roleInheritName))) {
		ZEPHIR_INIT_VAR(&_9$$9);
		object_init_ex(&_9$$9, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_10$$9);
		ZEPHIR_CONCAT_SVS(&_10$$9, "Role '", &roleInheritName, "' (to inherit) does not exist in the role list");
		ZEPHIR_CALL_METHOD(NULL, &_9$$9, "__construct", NULL, 4, &_10$$9);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_9$$9, "phalcon/acl/adapter/memory.zep", 249);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_EQUAL(&roleName, &roleInheritName)) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_11, this_ptr, SL("_roleInherits"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_11, &roleName))) {
		zephir_update_property_array(this_ptr, SL("_roleInherits"), &roleName, &__$true);
	}
	zephir_update_property_array_multi(this_ptr, SL("_roleInherits"), &roleInheritName, SL("za"), 2, &roleName);
	RETURN_MM_BOOL(1);

}

/**
 * Check whether role exist in the roles list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isRole) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *roleName_param = NULL, _0;
	zval roleName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &roleName_param);

	zephir_get_strval(&roleName, roleName_param);


	zephir_read_property(&_0, this_ptr, SL("_rolesNames"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &roleName));

}

/**
 * Check whether resource exist in the resources list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isResource) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *resourceName_param = NULL, _0;
	zval resourceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &resourceName_param);

	zephir_get_strval(&resourceName, resourceName_param);


	zephir_read_property(&_0, this_ptr, SL("_resourcesNames"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &resourceName));

}

/**
 * Adds a resource to the ACL list
 *
 * Access names can be a particular action, by example
 * search, update, delete, etc or a list of them
 *
 * Example:
 * <code>
 * // Add a resource to the the list allowing access to an action
 * $acl->addResource(
 *     new Phalcon\Acl\Resource("customers"),
 *     "search"
 * );
 *
 * $acl->addResource("customers", "search");
 *
 * // Add a resource  with an access list
 * $acl->addResource(
 *     new Phalcon\Acl\Resource("customers"),
 *     [
 *         "create",
 *         "search",
 *     ]
 * );
 *
 * $acl->addResource(
 *     "customers",
 *     [
 *         "create",
 *         "search",
 *     ]
 * );
 * </code>
 *
 * @param   Phalcon\Acl\Resource|string resourceValue
 * @param   array|string accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResource) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *resourceValue, resourceValue_sub, *accessList, accessList_sub, __$true, resourceName, resourceObject, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resourceValue_sub);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&resourceObject);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resourceValue, &accessList);



	_0 = Z_TYPE_P(resourceValue) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(resourceValue, phalcon_acl_resourceinterface_ce);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&resourceName, resourceValue, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&resourceObject, resourceValue);
	} else {
		ZEPHIR_CPY_WRT(&resourceName, resourceValue);
		ZEPHIR_INIT_NVAR(&resourceObject);
		object_init_ex(&resourceObject, phalcon_acl_resource_ce);
		ZEPHIR_CALL_METHOD(NULL, &resourceObject, "__construct", NULL, 77, &resourceName);
		zephir_check_call_status();
	}
	zephir_read_property(&_1, this_ptr, SL("_resourcesNames"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_1, &resourceName))) {
		zephir_update_property_array_append(this_ptr, SL("_resources"), &resourceObject);
		zephir_update_property_array(this_ptr, SL("_resourcesNames"), &resourceName, &__$true);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addresourceaccess", NULL, 0, &resourceName, accessList);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds access to resources
 *
 * @param array|string accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResourceAccess) {

	zend_bool exists = 0, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *resourceName_param = NULL, *accessList, accessList_sub, accessName, accessKey, _0, _1$$3, *_4$$5, _5$$5, _6$$6, _7$$7, _8$$8, _9$$9, _10$$10, _11$$11;
	zval resourceName, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resourceName_param, &accessList);

	zephir_get_strval(&resourceName, resourceName_param);


	zephir_read_property(&_0, this_ptr, SL("_resourcesNames"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &resourceName))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Resource '", &resourceName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 4, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/acl/adapter/memory.zep", 348);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = Z_TYPE_P(accessList) != IS_ARRAY;
	if (_3) {
		_3 = Z_TYPE_P(accessList) != IS_STRING;
	}
	if (_3) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Invalid value for accessList", "phalcon/acl/adapter/memory.zep", 352);
		return;
	}
	exists = 1;
	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		zephir_is_iterable(accessList, 0, "phalcon/acl/adapter/memory.zep", 363);
		if (Z_TYPE_P(accessList) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(accessList), _4$$5)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _4$$5);
				ZEPHIR_INIT_NVAR(&accessKey);
				ZEPHIR_CONCAT_VSV(&accessKey, &resourceName, "!", &accessName);
				zephir_read_property(&_6$$6, this_ptr, SL("_accessList"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset(&_6$$6, &accessKey))) {
					ZEPHIR_INIT_NVAR(&_7$$7);
					ZVAL_BOOL(&_7$$7, exists);
					zephir_update_property_array(this_ptr, SL("_accessList"), &accessKey, &_7$$7);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, accessList, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$5, accessList, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&accessName, accessList, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&accessKey);
					ZEPHIR_CONCAT_VSV(&accessKey, &resourceName, "!", &accessName);
					zephir_read_property(&_8$$8, this_ptr, SL("_accessList"), PH_NOISY_CC | PH_READONLY);
					if (!(zephir_array_isset(&_8$$8, &accessKey))) {
						ZEPHIR_INIT_NVAR(&_9$$9);
						ZVAL_BOOL(&_9$$9, exists);
						zephir_update_property_array(this_ptr, SL("_accessList"), &accessKey, &_9$$9);
					}
				ZEPHIR_CALL_METHOD(NULL, accessList, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		ZEPHIR_INIT_NVAR(&accessKey);
		ZEPHIR_CONCAT_VSV(&accessKey, &resourceName, "!", accessList);
		zephir_read_property(&_10$$10, this_ptr, SL("_accessList"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset(&_10$$10, &accessKey))) {
			ZEPHIR_INIT_VAR(&_11$$11);
			ZVAL_BOOL(&_11$$11, exists);
			zephir_update_property_array(this_ptr, SL("_accessList"), &accessKey, &_11$$11);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Removes an access from a resource
 *
 * @param array|string accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, dropResourceAccess) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *resourceName_param = NULL, *accessList, accessList_sub, accessName, accessKey, *_0$$3, _1$$3, _2$$4, _3$$5, _4$$6, _5$$7, _6$$9, _7$$10;
	zval resourceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resourceName_param, &accessList);

	zephir_get_strval(&resourceName, resourceName_param);


	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		zephir_is_iterable(accessList, 0, "phalcon/acl/adapter/memory.zep", 389);
		if (Z_TYPE_P(accessList) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(accessList), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _0$$3);
				ZEPHIR_INIT_NVAR(&accessKey);
				ZEPHIR_CONCAT_VSV(&accessKey, &resourceName, "!", &accessName);
				zephir_read_property(&_2$$4, this_ptr, SL("_accessList"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_2$$4, &accessKey)) {
					zephir_read_property(&_3$$5, this_ptr, SL("_accessList"), PH_NOISY_CC | PH_READONLY);
					zephir_array_unset(&_3$$5, &accessKey, PH_SEPARATE);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, accessList, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, accessList, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&accessName, accessList, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&accessKey);
					ZEPHIR_CONCAT_VSV(&accessKey, &resourceName, "!", &accessName);
					zephir_read_property(&_4$$6, this_ptr, SL("_accessList"), PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset(&_4$$6, &accessKey)) {
						zephir_read_property(&_5$$7, this_ptr, SL("_accessList"), PH_NOISY_CC | PH_READONLY);
						zephir_array_unset(&_5$$7, &accessKey, PH_SEPARATE);
					}
				ZEPHIR_CALL_METHOD(NULL, accessList, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		if (Z_TYPE_P(accessList) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSV(&accessKey, &resourceName, "!", &accessName);
			zephir_read_property(&_6$$9, this_ptr, SL("_accessList"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_6$$9, &accessKey)) {
				zephir_read_property(&_7$$10, this_ptr, SL("_accessList"), PH_NOISY_CC | PH_READONLY);
				zephir_array_unset(&_7$$10, &accessKey, PH_SEPARATE);
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if a role has access to a resource
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, _allowOrDeny) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *resourceName_param = NULL, *access, access_sub, *action, action_sub, *func = NULL, func_sub, __$null, accessList, accessName, accessKey, _0, _3, _1$$3, _4$$4, *_6$$5, _7$$5, *_12$$5, _13$$5, _8$$7, _9$$7, _10$$9, _11$$9, _14$$16, _15$$16;
	zval roleName, resourceName, _2$$3, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&access_sub);
	ZVAL_UNDEF(&action_sub);
	ZVAL_UNDEF(&func_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&accessList);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_14$$16);
	ZVAL_UNDEF(&_15$$16);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &roleName_param, &resourceName_param, &access, &action, &func);

	zephir_get_strval(&roleName, roleName_param);
	zephir_get_strval(&resourceName, resourceName_param);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_rolesNames"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &roleName))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Role '", &roleName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 4, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/acl/adapter/memory.zep", 407);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("_resourcesNames"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_3, &resourceName))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SVS(&_5$$4, "Resource '", &resourceName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 4, &_5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/acl/adapter/memory.zep", 411);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&accessList);
	zephir_read_property(&accessList, this_ptr, SL("_accessList"), PH_NOISY_CC);
	if (Z_TYPE_P(access) == IS_ARRAY) {
		zephir_is_iterable(access, 0, "phalcon/acl/adapter/memory.zep", 425);
		if (Z_TYPE_P(access) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(access), _6$$5)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _6$$5);
				ZEPHIR_INIT_NVAR(&accessKey);
				ZEPHIR_CONCAT_VSV(&accessKey, &resourceName, "!", &accessName);
				if (!(zephir_array_isset(&accessList, &accessKey))) {
					ZEPHIR_INIT_NVAR(&_8$$7);
					object_init_ex(&_8$$7, phalcon_acl_exception_ce);
					ZEPHIR_INIT_NVAR(&_9$$7);
					ZEPHIR_CONCAT_SVSVS(&_9$$7, "Access '", &accessName, "' does not exist in resource '", &resourceName, "'");
					ZEPHIR_CALL_METHOD(NULL, &_8$$7, "__construct", NULL, 4, &_9$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_8$$7, "phalcon/acl/adapter/memory.zep", 421);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, access, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_7$$5, access, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_7$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&accessName, access, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&accessKey);
					ZEPHIR_CONCAT_VSV(&accessKey, &resourceName, "!", &accessName);
					if (!(zephir_array_isset(&accessList, &accessKey))) {
						ZEPHIR_INIT_NVAR(&_10$$9);
						object_init_ex(&_10$$9, phalcon_acl_exception_ce);
						ZEPHIR_INIT_NVAR(&_11$$9);
						ZEPHIR_CONCAT_SVSVS(&_11$$9, "Access '", &accessName, "' does not exist in resource '", &resourceName, "'");
						ZEPHIR_CALL_METHOD(NULL, &_10$$9, "__construct", NULL, 4, &_11$$9);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_10$$9, "phalcon/acl/adapter/memory.zep", 421);
						ZEPHIR_MM_RESTORE();
						return;
					}
				ZEPHIR_CALL_METHOD(NULL, access, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&accessName);
		zephir_is_iterable(access, 0, "phalcon/acl/adapter/memory.zep", 434);
		if (Z_TYPE_P(access) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(access), _12$$5)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _12$$5);
				ZEPHIR_INIT_NVAR(&accessKey);
				ZEPHIR_CONCAT_VSVSV(&accessKey, &roleName, "!", &resourceName, "!", &accessName);
				zephir_update_property_array(this_ptr, SL("_access"), &accessKey, action);
				if (Z_TYPE_P(func) != IS_NULL) {
					zephir_update_property_array(this_ptr, SL("_func"), &accessKey, func);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, access, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_13$$5, access, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_13$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&accessName, access, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&accessKey);
					ZEPHIR_CONCAT_VSVSV(&accessKey, &roleName, "!", &resourceName, "!", &accessName);
					zephir_update_property_array(this_ptr, SL("_access"), &accessKey, action);
					if (Z_TYPE_P(func) != IS_NULL) {
						zephir_update_property_array(this_ptr, SL("_func"), &accessKey, func);
					}
				ZEPHIR_CALL_METHOD(NULL, access, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		if (!ZEPHIR_IS_STRING(access, "*")) {
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSV(&accessKey, &resourceName, "!", access);
			if (!(zephir_array_isset(&accessList, &accessKey))) {
				ZEPHIR_INIT_VAR(&_14$$16);
				object_init_ex(&_14$$16, phalcon_acl_exception_ce);
				ZEPHIR_INIT_VAR(&_15$$16);
				ZEPHIR_CONCAT_SVSVS(&_15$$16, "Access '", access, "' does not exist in resource '", &resourceName, "'");
				ZEPHIR_CALL_METHOD(NULL, &_14$$16, "__construct", NULL, 4, &_15$$16);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_14$$16, "phalcon/acl/adapter/memory.zep", 439);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_INIT_NVAR(&accessKey);
		ZEPHIR_CONCAT_VSVSV(&accessKey, &roleName, "!", &resourceName, "!", access);
		zephir_update_property_array(this_ptr, SL("_access"), &accessKey, action);
		if (Z_TYPE_P(func) != IS_NULL) {
			zephir_update_property_array(this_ptr, SL("_func"), &accessKey, func);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Allow access to a role on a resource
 *
 * You can use '*' as wildcard
 *
 * Example:
 * <code>
 * //Allow access to guests to search on customers
 * $acl->allow("guests", "customers", "search");
 *
 * //Allow access to guests to search or create on customers
 * $acl->allow("guests", "customers", ["search", "create"]);
 *
 * //Allow access to any role to browse on products
 * $acl->allow("*", "products", "browse");
 *
 * //Allow access to any role to browse on any resource
 * $acl->allow("*", "*", "browse");
 * </code>
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow) {

	zend_string *_6$$4;
	zend_ulong _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *resourceName_param = NULL, *access, access_sub, *func = NULL, func_sub, __$null, innerRoleName, _0$$3, _1$$4, _2$$4, *_3$$4, _4$$4, _7$$5, _8$$6;
	zval roleName, resourceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&access_sub);
	ZVAL_UNDEF(&func_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&innerRoleName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &roleName_param, &resourceName_param, &access, &func);

	zephir_get_strval(&roleName, roleName_param);
	zephir_get_strval(&resourceName, resourceName_param);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}


	if (!ZEPHIR_IS_STRING(&roleName, "*")) {
		ZVAL_LONG(&_0$$3, 1);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_allowordeny", NULL, 0, &roleName, &resourceName, access, &_0$$3, func);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		zephir_read_property(&_1$$4, this_ptr, SL("_rolesNames"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_is_iterable(&_1$$4, 0, "phalcon/acl/adapter/memory.zep", 486);
		if (Z_TYPE_P(&_1$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1$$4), _5$$4, _6$$4, _3$$4)
			{
				ZEPHIR_INIT_NVAR(&innerRoleName);
				if (_6$$4 != NULL) { 
					ZVAL_STR_COPY(&innerRoleName, _6$$4);
				} else {
					ZVAL_LONG(&innerRoleName, _5$$4);
				}
				ZEPHIR_INIT_NVAR(&_2$$4);
				ZVAL_COPY(&_2$$4, _3$$4);
				ZVAL_LONG(&_7$$5, 1);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_allowordeny", NULL, 0, &innerRoleName, &resourceName, access, &_7$$5, func);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$4, &_1$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&innerRoleName, &_1$$4, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_2$$4, &_1$$4, "current", NULL, 0);
				zephir_check_call_status();
					ZVAL_LONG(&_8$$6, 1);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_allowordeny", NULL, 0, &innerRoleName, &resourceName, access, &_8$$6, func);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_1$$4, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&_2$$4);
		ZEPHIR_INIT_NVAR(&innerRoleName);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Deny access to a role on a resource
 *
 * You can use '*' as wildcard
 *
 * Example:
 * <code>
 * //Deny access to guests to search on customers
 * $acl->deny("guests", "customers", "search");
 *
 * //Deny access to guests to search or create on customers
 * $acl->deny("guests", "customers", ["search", "create"]);
 *
 * //Deny access to any role to browse on products
 * $acl->deny("*", "products", "browse");
 *
 * //Deny access to any role to browse on any resource
 * $acl->deny("*", "*", "browse");
 * </code>
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, deny) {

	zend_string *_6$$4;
	zend_ulong _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *resourceName_param = NULL, *access, access_sub, *func = NULL, func_sub, __$null, innerRoleName, _0$$3, _1$$4, _2$$4, *_3$$4, _4$$4, _7$$5, _8$$6;
	zval roleName, resourceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&access_sub);
	ZVAL_UNDEF(&func_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&innerRoleName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &roleName_param, &resourceName_param, &access, &func);

	zephir_get_strval(&roleName, roleName_param);
	zephir_get_strval(&resourceName, resourceName_param);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}


	if (!ZEPHIR_IS_STRING(&roleName, "*")) {
		ZVAL_LONG(&_0$$3, 0);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_allowordeny", NULL, 0, &roleName, &resourceName, access, &_0$$3, func);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		zephir_read_property(&_1$$4, this_ptr, SL("_rolesNames"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_is_iterable(&_1$$4, 0, "phalcon/acl/adapter/memory.zep", 519);
		if (Z_TYPE_P(&_1$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1$$4), _5$$4, _6$$4, _3$$4)
			{
				ZEPHIR_INIT_NVAR(&innerRoleName);
				if (_6$$4 != NULL) { 
					ZVAL_STR_COPY(&innerRoleName, _6$$4);
				} else {
					ZVAL_LONG(&innerRoleName, _5$$4);
				}
				ZEPHIR_INIT_NVAR(&_2$$4);
				ZVAL_COPY(&_2$$4, _3$$4);
				ZVAL_LONG(&_7$$5, 0);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_allowordeny", NULL, 0, &innerRoleName, &resourceName, access, &_7$$5, func);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$4, &_1$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&innerRoleName, &_1$$4, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_2$$4, &_1$$4, "current", NULL, 0);
				zephir_check_call_status();
					ZVAL_LONG(&_8$$6, 0);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_allowordeny", NULL, 0, &innerRoleName, &resourceName, access, &_8$$6, func);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_1$$4, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&_2$$4);
		ZEPHIR_INIT_NVAR(&innerRoleName);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether a role is allowed to access an action from a resource
 *
 * <code>
 * //Does andres have access to the customers resource to create?
 * $acl->isAllowed("andres", "Products", "create");
 *
 * //Do guests have access to any resource to edit?
 * $acl->isAllowed("guests", "*", "edit");
 * </code>
 *
 * @param  RoleInterface|RoleAware|string roleName
 * @param  ResourceInterface|ResourceAware|string resourceName
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed) {

	zend_bool hasRole, hasResource, _14$$41, _18$$43, _20$$43, _21$$43, _23$$43, _24$$43, _26$$43, _36$$49, _38$$49, _39$$49, _41$$49, _42$$49, _44$$49, _56$$56, _58$$55, _60$$57;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_34 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval access;
	zval *roleName = NULL, roleName_sub, *resourceName = NULL, resourceName_sub, *access_param = NULL, *parameters_param = NULL, eventsManager, accessList, accessKey, haveAccess, roleInherits, inheritedRole, rolesNames, inheritedRoles, funcAccess, resourceObject, roleObject, funcList, reflectionFunction, reflectionParameters, parameterNumber, parametersForFunction, numberOfRequiredParameters, userParametersSizeShouldBe, reflectionClass, parameterToCheck, reflectionParameter, _2, _0$$5, _1$$9, _3$$11, _4$$11, _5$$13, *_6$$17, _7$$17, *_8$$25, _9$$25, *_10$$33, _11$$33, _12$$38, _13$$39, _15$$41, *_16$$40, _17$$40, _62$$40, _63$$40, _19$$43, _22$$43, _25$$43, _27$$43, _28$$43, _29$$46, _30$$46, _31$$46, _32$$46, _33$$46, _35$$47, _37$$49, _40$$49, _43$$49, _45$$49, _46$$49, _47$$52, _48$$52, _49$$52, _50$$52, _51$$52, _52$$53, _53$$54, _54$$54, _55$$56, _57$$56, _59$$55, _61$$57;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName_sub);
	ZVAL_UNDEF(&resourceName_sub);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&accessList);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&haveAccess);
	ZVAL_UNDEF(&roleInherits);
	ZVAL_UNDEF(&inheritedRole);
	ZVAL_UNDEF(&rolesNames);
	ZVAL_UNDEF(&inheritedRoles);
	ZVAL_UNDEF(&funcAccess);
	ZVAL_UNDEF(&resourceObject);
	ZVAL_UNDEF(&roleObject);
	ZVAL_UNDEF(&funcList);
	ZVAL_UNDEF(&reflectionFunction);
	ZVAL_UNDEF(&reflectionParameters);
	ZVAL_UNDEF(&parameterNumber);
	ZVAL_UNDEF(&parametersForFunction);
	ZVAL_UNDEF(&numberOfRequiredParameters);
	ZVAL_UNDEF(&userParametersSizeShouldBe);
	ZVAL_UNDEF(&reflectionClass);
	ZVAL_UNDEF(&parameterToCheck);
	ZVAL_UNDEF(&reflectionParameter);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$9);
	ZVAL_UNDEF(&_3$$11);
	ZVAL_UNDEF(&_4$$11);
	ZVAL_UNDEF(&_5$$13);
	ZVAL_UNDEF(&_7$$17);
	ZVAL_UNDEF(&_9$$25);
	ZVAL_UNDEF(&_11$$33);
	ZVAL_UNDEF(&_12$$38);
	ZVAL_UNDEF(&_13$$39);
	ZVAL_UNDEF(&_15$$41);
	ZVAL_UNDEF(&_17$$40);
	ZVAL_UNDEF(&_62$$40);
	ZVAL_UNDEF(&_63$$40);
	ZVAL_UNDEF(&_19$$43);
	ZVAL_UNDEF(&_22$$43);
	ZVAL_UNDEF(&_25$$43);
	ZVAL_UNDEF(&_27$$43);
	ZVAL_UNDEF(&_28$$43);
	ZVAL_UNDEF(&_29$$46);
	ZVAL_UNDEF(&_30$$46);
	ZVAL_UNDEF(&_31$$46);
	ZVAL_UNDEF(&_32$$46);
	ZVAL_UNDEF(&_33$$46);
	ZVAL_UNDEF(&_35$$47);
	ZVAL_UNDEF(&_37$$49);
	ZVAL_UNDEF(&_40$$49);
	ZVAL_UNDEF(&_43$$49);
	ZVAL_UNDEF(&_45$$49);
	ZVAL_UNDEF(&_46$$49);
	ZVAL_UNDEF(&_47$$52);
	ZVAL_UNDEF(&_48$$52);
	ZVAL_UNDEF(&_49$$52);
	ZVAL_UNDEF(&_50$$52);
	ZVAL_UNDEF(&_51$$52);
	ZVAL_UNDEF(&_52$$53);
	ZVAL_UNDEF(&_53$$54);
	ZVAL_UNDEF(&_54$$54);
	ZVAL_UNDEF(&_55$$56);
	ZVAL_UNDEF(&_57$$56);
	ZVAL_UNDEF(&_59$$55);
	ZVAL_UNDEF(&_61$$57);
	ZVAL_UNDEF(&access);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &roleName, &resourceName, &access_param, &parameters_param);

	ZEPHIR_SEPARATE_PARAM(roleName);
	ZEPHIR_SEPARATE_PARAM(resourceName);
	zephir_get_strval(&access, access_param);
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&haveAccess);
	ZVAL_NULL(&haveAccess);
	ZEPHIR_INIT_VAR(&funcAccess);
	ZVAL_NULL(&funcAccess);
	ZEPHIR_INIT_VAR(&resourceObject);
	ZVAL_NULL(&resourceObject);
	ZEPHIR_INIT_VAR(&roleObject);
	ZVAL_NULL(&roleObject);
	hasRole = 0;
	hasResource = 0;
	if (Z_TYPE_P(roleName) == IS_OBJECT) {
		if (zephir_instance_of_ev(roleName, phalcon_acl_roleaware_ce)) {
			ZEPHIR_CPY_WRT(&roleObject, roleName);
			ZEPHIR_CALL_METHOD(roleName, &roleObject, "getrolename", NULL, 0);
			zephir_check_call_status();
		} else if (zephir_instance_of_ev(roleName, phalcon_acl_roleinterface_ce)) {
			ZEPHIR_CALL_METHOD(&_0$$5, roleName, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(roleName, &_0$$5);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Object passed as roleName must implement Phalcon\\Acl\\RoleAware or Phalcon\\Acl\\RoleInterface", "phalcon/acl/adapter/memory.zep", 552);
			return;
		}
	}
	if (Z_TYPE_P(resourceName) == IS_OBJECT) {
		if (zephir_instance_of_ev(resourceName, phalcon_acl_resourceaware_ce)) {
			ZEPHIR_CPY_WRT(&resourceObject, resourceName);
			ZEPHIR_CALL_METHOD(resourceName, &resourceObject, "getresourcename", NULL, 0);
			zephir_check_call_status();
		} else if (zephir_instance_of_ev(resourceName, phalcon_acl_resourceinterface_ce)) {
			ZEPHIR_CALL_METHOD(&_1$$9, resourceName, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(resourceName, &_1$$9);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Object passed as resourceName must implement Phalcon\\Acl\\ResourceAware or Phalcon\\Acl\\ResourceInterface", "phalcon/acl/adapter/memory.zep", 563);
			return;
		}
	}
	zephir_update_property_zval(this_ptr, SL("_activeRole"), roleName);
	zephir_update_property_zval(this_ptr, SL("_activeResource"), resourceName);
	zephir_update_property_zval(this_ptr, SL("_activeAccess"), &access);
	ZEPHIR_OBS_VAR(&accessList);
	zephir_read_property(&accessList, this_ptr, SL("_access"), PH_NOISY_CC);
	zephir_read_property(&_2, this_ptr, SL("_eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_2);
	ZEPHIR_OBS_VAR(&funcList);
	zephir_read_property(&funcList, this_ptr, SL("_func"), PH_NOISY_CC);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_4$$11);
		ZVAL_STRING(&_4$$11, "acl:beforeCheckAccess");
		ZEPHIR_CALL_METHOD(&_3$$11, &eventsManager, "fire", NULL, 0, &_4$$11, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_3$$11)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_OBS_VAR(&rolesNames);
	zephir_read_property(&rolesNames, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(&rolesNames, roleName))) {
		zephir_read_property(&_5$$13, this_ptr, SL("_defaultAccess"), PH_NOISY_CC | PH_READONLY);
		RETURN_MM_BOOL((ZEPHIR_IS_LONG(&_5$$13, 1)));
	}
	ZEPHIR_INIT_VAR(&accessKey);
	ZEPHIR_CONCAT_VSVSV(&accessKey, roleName, "!", resourceName, "!", &access);
	if (zephir_array_isset(&accessList, &accessKey)) {
		ZEPHIR_OBS_NVAR(&haveAccess);
		zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 595);
	}
	ZEPHIR_OBS_NVAR(&funcAccess);
	zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0);
	if (Z_TYPE_P(&haveAccess) == IS_NULL) {
		ZEPHIR_OBS_VAR(&roleInherits);
		zephir_read_property(&roleInherits, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(&inheritedRoles);
		if (zephir_array_isset_fetch(&inheritedRoles, &roleInherits, roleName, 0)) {
			if (Z_TYPE_P(&inheritedRoles) == IS_ARRAY) {
				zephir_is_iterable(&inheritedRoles, 0, "phalcon/acl/adapter/memory.zep", 619);
				if (Z_TYPE_P(&inheritedRoles) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&inheritedRoles), _6$$17)
					{
						ZEPHIR_INIT_NVAR(&inheritedRole);
						ZVAL_COPY(&inheritedRole, _6$$17);
						ZEPHIR_INIT_NVAR(&accessKey);
						ZEPHIR_CONCAT_VSVSV(&accessKey, &inheritedRole, "!", resourceName, "!", &access);
						if (zephir_array_isset(&accessList, &accessKey)) {
							ZEPHIR_OBS_NVAR(&haveAccess);
							zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 615);
						}
						ZEPHIR_OBS_NVAR(&funcAccess);
						zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &inheritedRoles, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_7$$17, &inheritedRoles, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_7$$17)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&inheritedRole, &inheritedRoles, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&accessKey);
							ZEPHIR_CONCAT_VSVSV(&accessKey, &inheritedRole, "!", resourceName, "!", &access);
							if (zephir_array_isset(&accessList, &accessKey)) {
								ZEPHIR_OBS_NVAR(&haveAccess);
								zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 615);
							}
							ZEPHIR_OBS_NVAR(&funcAccess);
							zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0);
						ZEPHIR_CALL_METHOD(NULL, &inheritedRoles, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&inheritedRole);
			}
		}
	}
	if (Z_TYPE_P(&haveAccess) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&accessKey);
		ZEPHIR_CONCAT_VSVS(&accessKey, roleName, "!", resourceName, "!*");
		if (zephir_array_isset(&accessList, &accessKey)) {
			ZEPHIR_OBS_NVAR(&haveAccess);
			zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 634);
			ZEPHIR_OBS_NVAR(&funcAccess);
			zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0);
		} else {
			if (Z_TYPE_P(&inheritedRoles) == IS_ARRAY) {
				zephir_is_iterable(&inheritedRoles, 0, "phalcon/acl/adapter/memory.zep", 650);
				if (Z_TYPE_P(&inheritedRoles) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&inheritedRoles), _8$$25)
					{
						ZEPHIR_INIT_NVAR(&inheritedRole);
						ZVAL_COPY(&inheritedRole, _8$$25);
						ZEPHIR_INIT_NVAR(&accessKey);
						ZEPHIR_CONCAT_VSVS(&accessKey, &inheritedRole, "!", resourceName, "!*");
						ZEPHIR_OBS_NVAR(&funcAccess);
						zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0);
						if (zephir_array_isset(&accessList, &accessKey)) {
							ZEPHIR_OBS_NVAR(&haveAccess);
							zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 646);
							break;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &inheritedRoles, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_9$$25, &inheritedRoles, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_9$$25)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&inheritedRole, &inheritedRoles, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&accessKey);
							ZEPHIR_CONCAT_VSVS(&accessKey, &inheritedRole, "!", resourceName, "!*");
							ZEPHIR_OBS_NVAR(&funcAccess);
							zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0);
							if (zephir_array_isset(&accessList, &accessKey)) {
								ZEPHIR_OBS_NVAR(&haveAccess);
								zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 646);
								break;
							}
						ZEPHIR_CALL_METHOD(NULL, &inheritedRoles, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&inheritedRole);
			}
		}
	}
	if (Z_TYPE_P(&haveAccess) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&accessKey);
		ZEPHIR_CONCAT_VS(&accessKey, roleName, "!*!*");
		if (zephir_array_isset(&accessList, &accessKey)) {
			ZEPHIR_OBS_NVAR(&haveAccess);
			zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 665);
			ZEPHIR_OBS_NVAR(&funcAccess);
			zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0);
		} else {
			if (Z_TYPE_P(&inheritedRoles) == IS_ARRAY) {
				zephir_is_iterable(&inheritedRoles, 0, "phalcon/acl/adapter/memory.zep", 681);
				if (Z_TYPE_P(&inheritedRoles) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&inheritedRoles), _10$$33)
					{
						ZEPHIR_INIT_NVAR(&inheritedRole);
						ZVAL_COPY(&inheritedRole, _10$$33);
						ZEPHIR_INIT_NVAR(&accessKey);
						ZEPHIR_CONCAT_VS(&accessKey, &inheritedRole, "!*!*");
						ZEPHIR_OBS_NVAR(&funcAccess);
						zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0);
						if (zephir_array_isset(&accessList, &accessKey)) {
							ZEPHIR_OBS_NVAR(&haveAccess);
							zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 677);
							break;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &inheritedRoles, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_11$$33, &inheritedRoles, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_11$$33)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&inheritedRole, &inheritedRoles, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&accessKey);
							ZEPHIR_CONCAT_VS(&accessKey, &inheritedRole, "!*!*");
							ZEPHIR_OBS_NVAR(&funcAccess);
							zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0);
							if (zephir_array_isset(&accessList, &accessKey)) {
								ZEPHIR_OBS_NVAR(&haveAccess);
								zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 677);
								break;
							}
						ZEPHIR_CALL_METHOD(NULL, &inheritedRoles, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&inheritedRole);
			}
		}
	}
	zephir_update_property_zval(this_ptr, SL("_accessGranted"), &haveAccess);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_12$$38);
		ZVAL_STRING(&_12$$38, "acl:afterCheckAccess");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_12$$38, this_ptr);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&haveAccess) == IS_NULL) {
		zephir_read_property(&_13$$39, this_ptr, SL("_defaultAccess"), PH_NOISY_CC | PH_READONLY);
		RETURN_MM_BOOL(ZEPHIR_IS_LONG(&_13$$39, 1));
	}
	if (Z_TYPE_P(&funcAccess) != IS_NULL) {
		ZEPHIR_INIT_VAR(&reflectionFunction);
		object_init_ex(&reflectionFunction, zephir_get_internal_ce(SL("reflectionfunction")));
		ZEPHIR_CALL_METHOD(NULL, &reflectionFunction, "__construct", NULL, 78, &funcAccess);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&reflectionParameters, &reflectionFunction, "getparameters", NULL, 79);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&parameterNumber);
		ZVAL_LONG(&parameterNumber, zephir_fast_count_int(&reflectionParameters));
		if (ZEPHIR_IS_LONG_IDENTICAL(&parameterNumber, 0)) {
			_14$$41 = ZEPHIR_IS_LONG(&haveAccess, 1);
			if (_14$$41) {
				ZEPHIR_INIT_VAR(&_15$$41);
				ZEPHIR_CALL_USER_FUNC(&_15$$41, &funcAccess);
				zephir_check_call_status();
				_14$$41 = zephir_is_true(&_15$$41);
			}
			RETURN_MM_BOOL(_14$$41);
		}
		ZEPHIR_INIT_VAR(&parametersForFunction);
		array_init(&parametersForFunction);
		ZEPHIR_CALL_METHOD(&numberOfRequiredParameters, &reflectionFunction, "getnumberofrequiredparameters", NULL, 80);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&userParametersSizeShouldBe, &parameterNumber);
		zephir_is_iterable(&reflectionParameters, 0, "phalcon/acl/adapter/memory.zep", 748);
		if (Z_TYPE_P(&reflectionParameters) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&reflectionParameters), _16$$40)
			{
				ZEPHIR_INIT_NVAR(&reflectionParameter);
				ZVAL_COPY(&reflectionParameter, _16$$40);
				ZEPHIR_CALL_METHOD(&reflectionClass, &reflectionParameter, "getclass", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&parameterToCheck, &reflectionParameter, "getname", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&reflectionClass) != IS_NULL) {
					_18$$43 = Z_TYPE_P(&roleObject) != IS_NULL;
					if (_18$$43) {
						ZEPHIR_CALL_METHOD(&_19$$43, &reflectionClass, "isinstance", NULL, 0, &roleObject);
						zephir_check_call_status();
						_18$$43 = zephir_is_true(&_19$$43);
					}
					_20$$43 = _18$$43;
					if (_20$$43) {
						_20$$43 = !hasRole;
					}
					if (_20$$43) {
						hasRole = 1;
						zephir_array_append(&parametersForFunction, &roleObject, PH_SEPARATE, "phalcon/acl/adapter/memory.zep", 719);
						ZEPHIR_SEPARATE(&userParametersSizeShouldBe);
						zephir_decrement(&userParametersSizeShouldBe);
						continue;
					}
					_21$$43 = Z_TYPE_P(&resourceObject) != IS_NULL;
					if (_21$$43) {
						ZEPHIR_CALL_METHOD(&_22$$43, &reflectionClass, "isinstance", NULL, 0, &resourceObject);
						zephir_check_call_status();
						_21$$43 = zephir_is_true(&_22$$43);
					}
					_23$$43 = _21$$43;
					if (_23$$43) {
						_23$$43 = !hasResource;
					}
					if (_23$$43) {
						hasResource = 1;
						zephir_array_append(&parametersForFunction, &resourceObject, PH_SEPARATE, "phalcon/acl/adapter/memory.zep", 728);
						ZEPHIR_SEPARATE(&userParametersSizeShouldBe);
						zephir_decrement(&userParametersSizeShouldBe);
						continue;
					}
					_24$$43 = zephir_array_isset(&parameters, &parameterToCheck);
					if (_24$$43) {
						ZEPHIR_OBS_NVAR(&_25$$43);
						zephir_array_fetch(&_25$$43, &parameters, &parameterToCheck, PH_NOISY, "phalcon/acl/adapter/memory.zep", 735);
						_24$$43 = Z_TYPE_P(&_25$$43) == IS_OBJECT;
					}
					_26$$43 = _24$$43;
					if (_26$$43) {
						zephir_array_fetch(&_28$$43, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 735);
						ZEPHIR_CALL_METHOD(&_27$$43, &reflectionClass, "isinstance", NULL, 0, &_28$$43);
						zephir_check_call_status();
						_26$$43 = !zephir_is_true(&_27$$43);
					}
					if (_26$$43) {
						ZEPHIR_INIT_NVAR(&_29$$46);
						object_init_ex(&_29$$46, phalcon_acl_exception_ce);
						ZEPHIR_INIT_NVAR(&_30$$46);
						zephir_array_fetch(&_31$$46, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 737);
						zephir_get_class(&_30$$46, &_31$$46, 0);
						ZEPHIR_CALL_METHOD(&_32$$46, &reflectionClass, "getname", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_33$$46);
						ZEPHIR_CONCAT_SVSVSVSVSVS(&_33$$46, "Your passed parameter doesn't have the same class as the parameter in defined function when check ", roleName, " can ", &access, " ", resourceName, ". Class passed: ", &_30$$46, " , Class in defined function: ", &_32$$46, ".");
						ZEPHIR_CALL_METHOD(NULL, &_29$$46, "__construct", &_34, 4, &_33$$46);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_29$$46, "phalcon/acl/adapter/memory.zep", 738);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				if (zephir_array_isset(&parameters, &parameterToCheck)) {
					zephir_array_fetch(&_35$$47, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 744);
					zephir_array_append(&parametersForFunction, &_35$$47, PH_SEPARATE, "phalcon/acl/adapter/memory.zep", 744);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &reflectionParameters, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_17$$40, &reflectionParameters, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_17$$40)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&reflectionParameter, &reflectionParameters, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&reflectionClass, &reflectionParameter, "getclass", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&parameterToCheck, &reflectionParameter, "getname", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&reflectionClass) != IS_NULL) {
						_36$$49 = Z_TYPE_P(&roleObject) != IS_NULL;
						if (_36$$49) {
							ZEPHIR_CALL_METHOD(&_37$$49, &reflectionClass, "isinstance", NULL, 0, &roleObject);
							zephir_check_call_status();
							_36$$49 = zephir_is_true(&_37$$49);
						}
						_38$$49 = _36$$49;
						if (_38$$49) {
							_38$$49 = !hasRole;
						}
						if (_38$$49) {
							hasRole = 1;
							zephir_array_append(&parametersForFunction, &roleObject, PH_SEPARATE, "phalcon/acl/adapter/memory.zep", 719);
							ZEPHIR_SEPARATE(&userParametersSizeShouldBe);
							zephir_decrement(&userParametersSizeShouldBe);
							continue;
						}
						_39$$49 = Z_TYPE_P(&resourceObject) != IS_NULL;
						if (_39$$49) {
							ZEPHIR_CALL_METHOD(&_40$$49, &reflectionClass, "isinstance", NULL, 0, &resourceObject);
							zephir_check_call_status();
							_39$$49 = zephir_is_true(&_40$$49);
						}
						_41$$49 = _39$$49;
						if (_41$$49) {
							_41$$49 = !hasResource;
						}
						if (_41$$49) {
							hasResource = 1;
							zephir_array_append(&parametersForFunction, &resourceObject, PH_SEPARATE, "phalcon/acl/adapter/memory.zep", 728);
							ZEPHIR_SEPARATE(&userParametersSizeShouldBe);
							zephir_decrement(&userParametersSizeShouldBe);
							continue;
						}
						_42$$49 = zephir_array_isset(&parameters, &parameterToCheck);
						if (_42$$49) {
							ZEPHIR_OBS_NVAR(&_43$$49);
							zephir_array_fetch(&_43$$49, &parameters, &parameterToCheck, PH_NOISY, "phalcon/acl/adapter/memory.zep", 735);
							_42$$49 = Z_TYPE_P(&_43$$49) == IS_OBJECT;
						}
						_44$$49 = _42$$49;
						if (_44$$49) {
							zephir_array_fetch(&_46$$49, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 735);
							ZEPHIR_CALL_METHOD(&_45$$49, &reflectionClass, "isinstance", NULL, 0, &_46$$49);
							zephir_check_call_status();
							_44$$49 = !zephir_is_true(&_45$$49);
						}
						if (_44$$49) {
							ZEPHIR_INIT_NVAR(&_47$$52);
							object_init_ex(&_47$$52, phalcon_acl_exception_ce);
							ZEPHIR_INIT_NVAR(&_48$$52);
							zephir_array_fetch(&_49$$52, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 737);
							zephir_get_class(&_48$$52, &_49$$52, 0);
							ZEPHIR_CALL_METHOD(&_50$$52, &reflectionClass, "getname", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_51$$52);
							ZEPHIR_CONCAT_SVSVSVSVSVS(&_51$$52, "Your passed parameter doesn't have the same class as the parameter in defined function when check ", roleName, " can ", &access, " ", resourceName, ". Class passed: ", &_48$$52, " , Class in defined function: ", &_50$$52, ".");
							ZEPHIR_CALL_METHOD(NULL, &_47$$52, "__construct", &_34, 4, &_51$$52);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_47$$52, "phalcon/acl/adapter/memory.zep", 738);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					if (zephir_array_isset(&parameters, &parameterToCheck)) {
						zephir_array_fetch(&_52$$53, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 744);
						zephir_array_append(&parametersForFunction, &_52$$53, PH_SEPARATE, "phalcon/acl/adapter/memory.zep", 744);
					}
				ZEPHIR_CALL_METHOD(NULL, &reflectionParameters, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&reflectionParameter);
		if (ZEPHIR_LT_LONG(&userParametersSizeShouldBe, zephir_fast_count_int(&parameters))) {
			ZEPHIR_INIT_VAR(&_53$$54);
			ZEPHIR_CONCAT_SVSVSVS(&_53$$54, "Number of parameters in array is higher than the number of parameters in defined function when check ", roleName, " can ", &access, " ", resourceName, ". Remember that more parameters than defined in function will be ignored.");
			ZVAL_LONG(&_54$$54, 512);
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 1, &_53$$54, &_54$$54);
			zephir_check_call_status();
		}
		if (zephir_fast_count_int(&parametersForFunction) == 0) {
			if (ZEPHIR_GT_LONG(&numberOfRequiredParameters, 0)) {
				ZEPHIR_INIT_VAR(&_55$$56);
				ZEPHIR_CONCAT_SVSVSVS(&_55$$56, "You didn't provide any parameters when check ", roleName, " can ", &access, " ", resourceName, ". We will use default action when no arguments.");
				ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 1, &_55$$56);
				zephir_check_call_status();
				_56$$56 = ZEPHIR_IS_LONG(&haveAccess, 1);
				if (_56$$56) {
					zephir_read_property(&_57$$56, this_ptr, SL("_noArgumentsDefaultAction"), PH_NOISY_CC | PH_READONLY);
					_56$$56 = ZEPHIR_IS_LONG(&_57$$56, 1);
				}
				RETURN_MM_BOOL(_56$$56);
			}
			_58$$55 = ZEPHIR_IS_LONG(&haveAccess, 1);
			if (_58$$55) {
				ZEPHIR_INIT_VAR(&_59$$55);
				ZEPHIR_CALL_USER_FUNC(&_59$$55, &funcAccess);
				zephir_check_call_status();
				_58$$55 = zephir_is_true(&_59$$55);
			}
			RETURN_MM_BOOL(_58$$55);
		}
		if (ZEPHIR_LE_LONG(&numberOfRequiredParameters, zephir_fast_count_int(&parametersForFunction))) {
			_60$$57 = ZEPHIR_IS_LONG(&haveAccess, 1);
			if (_60$$57) {
				ZEPHIR_INIT_VAR(&_61$$57);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&_61$$57, &funcAccess, &parametersForFunction);
				zephir_check_call_status();
				_60$$57 = zephir_is_true(&_61$$57);
			}
			RETURN_MM_BOOL(_60$$57);
		}
		ZEPHIR_INIT_VAR(&_62$$40);
		object_init_ex(&_62$$40, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_63$$40);
		ZEPHIR_CONCAT_SVSVSV(&_63$$40, "You didn't provide all necessary parameters for defined function when check ", roleName, " can ", &access, " ", resourceName);
		ZEPHIR_CALL_METHOD(NULL, &_62$$40, "__construct", &_34, 4, &_63$$40);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_62$$40, "phalcon/acl/adapter/memory.zep", 777);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(&haveAccess, 1));

}

/**
 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
 * for no arguments provided in isAllowed action if there exists func for
 * accessKey
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, setNoArgumentsDefaultAction) {

	zval *defaultAccess_param = NULL, _0;
	zend_long defaultAccess;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(1, 0, &defaultAccess_param);

	defaultAccess = zephir_get_intval(defaultAccess_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, defaultAccess);
	zephir_update_property_zval(this_ptr, SL("_noArgumentsDefaultAction"), &_0);

}

/**
 * Returns the default ACL access level for no arguments provided in
 * isAllowed action if there exists func for accessKey
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getNoArgumentsDefaultAction) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_noArgumentsDefaultAction");

}

/**
 * Return an array with every role registered in the list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getRoles) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_roles");

}

/**
 * Return an array with every resource registered in the list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getResources) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_resources");

}

