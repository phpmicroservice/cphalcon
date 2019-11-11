
extern zend_class_entry *phalcon_mvc_model_transaction_managerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Transaction_ManagerInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_has, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_has, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_get, 0, 0, Phalcon\\Mvc\\Model\\TransactionInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_get, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\Model\\TransactionInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, autoBegin, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, autoBegin)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, collect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_notifyrollback, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, transaction, Phalcon\\Mvc\\Model\\TransactionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_notifycommit, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, transaction, Phalcon\\Mvc\\Model\\TransactionInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_transaction_managerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, has, arginfo_phalcon_mvc_model_transaction_managerinterface_has)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, get, arginfo_phalcon_mvc_model_transaction_managerinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, rollbackPendent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, commit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, rollback, arginfo_phalcon_mvc_model_transaction_managerinterface_rollback)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, notifyRollback, arginfo_phalcon_mvc_model_transaction_managerinterface_notifyrollback)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, notifyCommit, arginfo_phalcon_mvc_model_transaction_managerinterface_notifycommit)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, collectTransactions, NULL)
	PHP_FE_END
};
