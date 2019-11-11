
extern zend_class_entry *phalcon_validation_validator_stringlength_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_StringLength);

PHP_METHOD(Phalcon_Validation_Validator_StringLength, validate);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_validator_stringlength_validate, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_validator_stringlength_validate, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, field)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_stringlength_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_StringLength, validate, arginfo_phalcon_validation_validator_stringlength_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
