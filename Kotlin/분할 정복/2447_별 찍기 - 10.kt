/* BOJ - 2447 별 찍기 - 10 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader

val stringBuilder = StringBuilder()

fun star(x: Int, y: Int, n: Int) {
    if ((x / n) % 3 == 1 && (y / n) % 3 == 1) {
        stringBuilder.append(' ')
    } else {
        when (n / 3) {
            0 -> stringBuilder.append('*')
            else -> star(x, y, n / 3)
        }
    }
}

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val n = reader.readLine().toInt()
    for (y in 0 until n) {
        for (x in 0 until n) {
            star(x, y, n)
        }
        stringBuilder.appendLine()
    }
    print(stringBuilder)
}