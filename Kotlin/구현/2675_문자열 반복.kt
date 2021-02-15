/* BOJ - 2675 문자열 반복 */

package boj

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val bufferedWriter = BufferedWriter(OutputStreamWriter(System.out))

    for (testcase in 1..bufferedReader.readLine().toInt()) {
        val token = StringTokenizer(bufferedReader.readLine())
        val length = token.nextToken().toInt()
        val string = token.nextToken()

        for (char in string) {
            repeat(length) {
                bufferedWriter.write("$char")
            }
        }
        bufferedWriter.newLine()
    }

    bufferedReader.close()
    bufferedWriter.close()
}