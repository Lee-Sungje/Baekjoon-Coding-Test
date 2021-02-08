/* BOJ - 1330 두 수 비교하기 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val numbers = StringTokenizer(bufferedReader.readLine())
    val a = numbers.nextToken().toInt()
    val b = numbers.nextToken().toInt()

    val answer: String = if (a < b) "<" else if (a > b) ">" else "=="
    println(answer)
}