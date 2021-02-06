/* BOJ - 2724 기찍 N */

package boj

import java.lang.StringBuilder

fun main() {
    val n = readLine()!!.toInt()
    val stringBuilder = StringBuilder()

    for (i in n downTo 1) {
        stringBuilder.append("$i\n")
    }
    print(stringBuilder)
}