/*
 * copyright 2019 viraltaco_
 * SPDX-License-Identifier: MIT
 * <http://www.opensource.org/licenses/MIT>
 */

class BracketPush {

  /*
   * Inspired by D3Portillo's solution.
   * <https://exercism.io/tracks/dart/exercises/bracket-push/solutions/7fde3b81887b423eb5ba82e21b74218b>
   */
  bool isPaired(String str)
  => str.replaceAll(new RegExp(r'[^\{\}\[\]\(\)]'), '')
        .replaceAll(new RegExp(r'\{\}|\(\)|\[\]'), '')
        .isEmpty
  ;
}
