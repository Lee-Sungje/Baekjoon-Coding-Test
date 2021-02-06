/* BOJ - 2439 별 찍기 - 2 */

package boj

import kotlin.text.StringBuilder

fun repeatedPattern(pattern: Char, length: Int): StringBuilder {
    val sb = StringBuilder()
    for (i in 1..length) {
        sb.append(pattern)
    }
    return sb
}

fun main() {
    val stringBuilder = StringBuilder()
    val n = readLine()!!.toInt()

    for (i in 1..n) {
        stringBuilder.append(repeatedPattern(' ', n - i))
        stringBuilder.append(repeatedPattern('*', i))
        stringBuilder.append('\n')
    }
    print(stringBuilder)
}