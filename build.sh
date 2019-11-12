#!/bin/bash

# cd /home/cphalcon;/home/zephir-0.12.11/zephir fullclean;
/home/zephir-0.12.11/zephir build
/home/zephir-0.12.11/zephir stubs
cd /home/cphalcon/build;php gen-build.php
./install