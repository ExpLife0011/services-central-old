/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is
 * Alexander J. Vincent <ajvincent@gmail.com>
 * Portions created by the Initial Developer are Copyright (C) 2011
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either of the GNU General Public License Version 2 or later (the "GPL"),
 * or the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#include "mozilla/ModuleUtils.h"

// f18fb09b-28b4-4435-bc5b-8027f18df743
#define NS_TESTING_CID \
{ 0xf18fb09b, 0x28b4, 0x4435, \
  { 0xbc, 0x5b, 0x80, 0x27, 0xf1, 0x8d, 0xf7, 0x43 } }

NS_DEFINE_NAMED_CID(NS_TESTING_CID);

static nsresult
DummyConstructorFunc(nsISupports* aOuter, const nsIID& aIID, void** aResult)
{
  return NS_ERROR_NOT_IMPLEMENTED;
}

static const mozilla::Module::CIDEntry kTestCIDs[] = {
  { &kNS_TESTING_CID, false, NULL, DummyConstructorFunc },
  { NULL }
};

static const mozilla::Module kTestModule = {
  3, /* faking mozilla::Module::kVersion with a value that will never be used */
  kTestCIDs
};

NSMODULE_DEFN(dummy) = &kTestModule;