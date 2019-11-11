
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * Loads Paginator Adapter class using 'adapter' option
 *
 *<code>
 * use Phalcon\Paginator\Factory;
 * $builder = $this->modelsManager->createBuilder()
 *                 ->columns("id, name")
 *                 ->from("Robots")
 *                 ->orderBy("name");
 *
 * $options = [
 *     "builder" => $builder,
 *     "limit"   => 20,
 *     "page"    => 1,
 *     "adapter" => "queryBuilder",
 * ];
 * $paginator = Factory::load($options);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_Factory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Paginator, Factory, phalcon, paginator_factory, phalcon_factory_ce, phalcon_paginator_factory_method_entry, 0);

	return SUCCESS;

}

/**
 * @param \Phalcon\Config|array config
 */
PHP_METHOD(Phalcon_Paginator_Factory, load) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, config_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Phalcon\\Paginator\\Adapter");
	ZEPHIR_RETURN_CALL_SELF("loadclass", NULL, 0, &_0, config);
	zephir_check_call_status();
	RETURN_MM();

}

