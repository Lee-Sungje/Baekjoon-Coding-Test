/* BOJ - 15552 빠른 A+B */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val stringBuilder = StringBuilder()

    for (testcase in 1..bufferedReader.readLine().toInt()) {
        val token = StringTokenizer(bufferedReader.readLine())
        val a = token.nextToken().toInt()
        val b = token.nextToken().toInt()

        stringBuilder.append("${a + b}\n")
    }

    print(stringBuilder)
    bufferedReader.close()
}