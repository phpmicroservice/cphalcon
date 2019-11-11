
extern zend_class_entry *phalcon_validationinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_ValidationInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_validationinterface_validate, 0, 0, Phalcon\\Validation\\Message\\Group, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validationinterface_validate, 0, 0, IS_OBJECT, "Phalcon\\Validation\\Message\\Group", 0)
#endif
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_validationinterface_add, 0, 2, Phalcon\\Validation, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validationinterface_add, 0, 2, IS_OBJECT, "Phalcon\\Validation", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, field)
#endif
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Validation\\ValidatorInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_validationinterface_rule, 0, 2, Phalcon\\Validation, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validationinterface_rule, 0, 2, IS_OBJECT, "Phalcon\\Validation", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, field)
#endif
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Validation\\ValidatorInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_validationinterface_rules, 0, 2, Phalcon\\Validation, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validationinterface_rules, 0, 2, IS_OBJECT, "Phalcon\\Validation", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, field)
#endif
	ZEND_ARG_ARRAY_INFO(0, validators, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_validationinterface_setfilters, 0, 2, Phalcon\\Validation, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validationinterface_setfilters, 0, 2, IS_OBJECT, "Phalcon\\Validation", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, field)
#endif
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validationinterface_getfilters, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, field)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validationinterface_setdefaultmessages, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, messages, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validationinterface_getdefaultmessage, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_validationinterface_getmessages, 0, 0, Phalcon\\Validation\\Message\\Group, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validationinterface_getmessages, 0, 0, IS_OBJECT, "Phalcon\\Validation\\Message\\Group", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validationinterface_setlabels, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, labels, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validationinterface_getlabel, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, field)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validationinterface_appendmessage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Validation\\MessageInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_validationinterface_bind, 0, 2, Phalcon\\Validation, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validationinterface_bind, 0, 2, IS_OBJECT, "Phalcon\\Validation", 0)
#endif
	ZEND_ARG_INFO(0, entity)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validationinterface_getvalue, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, field)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validationinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_ValidationInterface, validate, arginfo_phalcon_validationinterface_validate)
	PHP_ABSTRACT_ME(Phalcon_ValidationInterface, add, arginfo_phalcon_validationinterface_add)
	PHP_ABSTRACT_ME(Phalcon_ValidationInterface, rule, arginfo_phalcon_validationinterface_rule)
	PHP_ABSTRACT_ME(Phalcon_ValidationInterface, rules, arginfo_phalcon_validationinterface_rules)
	PHP_ABSTRACT_ME(Phalcon_ValidationInterface, setFilters, arginfo_phalcon_validationinterface_setfilters)
	PHP_ABSTRACT_ME(Phalcon_ValidationInterface, getFilters, arginfo_phalcon_validationinterface_getfilters)
	PHP_ABSTRACT_ME(Phalcon_ValidationInterface, getValidators, NULL)
	PHP_ABSTRACT_ME(Phalcon_ValidationInterface, getEntity, NULL)
	PHP_ABSTRACT_ME(Phalcon_ValidationInterface, setDefaultMessages, arginfo_phalcon_validationinterface_setdefaultmessages)
	PHP_ABSTRACT_ME(Phalcon_ValidationInterface, getDefaultMessage, arginfo_phalcon_validationinterface_getdefaultmessage)
	PHP_ABSTRACT_ME(Phalcon_ValidationInterface, getMessages, arginfo_phalcon_validationinterface_getmessages)
	PHP_ABSTRACT_ME(Phalcon_ValidationInterface, setLabels, arginfo_phalcon_validationinterface_setlabels)
	PHP_ABSTRACT_ME(Phalcon_ValidationInterface, getLabel, arginfo_phalcon_validationinterface_getlabel)
	PHP_ABSTRACT_ME(Phalcon_ValidationInterface, appendMessage, arginfo_phalcon_validationinterface_appendmessage)
	PHP_ABSTRACT_ME(Phalcon_ValidationInterface, bind, arginfo_phalcon_validationinterface_bind)
	PHP_ABSTRACT_ME(Phalcon_ValidationInterface, getValue, arginfo_phalcon_validationinterface_getvalue)
	PHP_FE_END
};
