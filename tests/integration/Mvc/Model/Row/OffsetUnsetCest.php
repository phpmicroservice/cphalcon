<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\Row;

use IntegrationTester;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\Row;

class OffsetUnsetCest
{
    /**
     * Tests Phalcon\Mvc\Model\Row :: offsetUnset()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-01
     */
    public function mvcModelRowOffsetUnset(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Row - offsetUnset()');

        $row = new Row();

        $row->writeAttribute('estado', 'A');

        $I->expectThrowable(
            new Exception('Row is an immutable ArrayAccess object'),
            function () use ($row) {
                unset($row['estado']);
            }
        );
    }
}
