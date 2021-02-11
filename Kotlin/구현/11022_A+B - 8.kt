/* BOJ - 11022 A+B - 8 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val stringBuilder = StringBuilder()

    for (testcase in 1..bufferedReader.readLine().toInt()) {
        val stringTokenizer = StringTokenizer(bufferedReader.readLine())
        val a = stringTokenizer.nextToken().toInt()
        val b = stringTokenizer.nextToken().toInt()

        stringBuilder.append("Case #$testcase: $a + $b = ${a + b}\n")
    }

    println(stringBuilder)
    bufferedReader.close()
}