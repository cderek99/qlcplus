/*
  Q Light Controller
  script_test.cpp

  Copyright (C) Heikki Junnila

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#include <QtTest>

#define private public

#include "qlcfixturedefcache.h"
#include "universearray.h"
#include "mastertimer.h"
#include "script_test.h"
#include "script.h"
#include "doc.h"

#undef private

static QString script0(
"// Comment over there\n"
"startfunction:12\r"
"stopscript:5 // Comment in here\n"
"stopfunction:33 paska\n"
"waitkey:\"SHIFT+K\"\n"
"startfunction:\"54\"\r\n"
"wait:1.05\n"
"setdmx:12 uni:2 val:127\n"
"setfixture:99 value:255 channel:1\n"
);

void Script_Test::initTestCase()
{
}
void Script_Test::initial()
{
    Doc doc(this);
    UniverseArray ua(512 * 4);

    Script scr(&doc);
    scr.setData(script0);

    for (int i = 0; i < 9; i++)
        scr.executeCommand(i, doc.masterTimer(), &ua);
}

QTEST_APPLESS_MAIN(Script_Test)
