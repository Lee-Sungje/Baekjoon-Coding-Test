/* BOJ - 2442_별 찍기 - 5 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader

fun makeStar(size: Int) = StringBuilder().apply {
    for (count in 1..size) {
        this.appendLine(" ".repeat(size - count) + "*".repeat(2 * count - 1))
    }
}

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val n = reader.readLine().toInt()
    print(makeStar(n))
}