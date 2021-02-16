/* BOJ - 1924 2007년 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

val month = listOf(0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)
val week = listOf("SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT")

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`)).let {
        val token = StringTokenizer(it.readLine())
        val thisMonth = token.nextToken().toInt()
        var untilToday = token.nextToken().toInt()
        repeat(thisMonth) { index -> untilToday += month[index] }

        println(week[untilToday % week.size])
        it.close()
    }
}