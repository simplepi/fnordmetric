/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2011-2014 Paul Asmuth, Google Inc.
 *
 * FnordMetric is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#ifndef _FNORDMETRIC_UTIL_SIGNALHANDLER_H
#define _FNORDMETRIC_UTIL_SIGNALHANDLER_H

namespace fnordmetric {
namespace util {

class SignalHandler {
public:

  static void ignoreSIGHUP();
  static void ignoreSIGPIPE();

};

}
}
#endif
