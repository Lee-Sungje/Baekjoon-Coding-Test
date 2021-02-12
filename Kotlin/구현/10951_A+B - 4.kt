/* BOJ - 10951 A+B - 4 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val stringBuilder = StringBuilder()

    do {
        val input = bufferedReader.readLine() ?: break
        StringTokenizer(input).let {
            val a = it.nextToken().toInt()
            val b = it.nextToken().toInt()
            stringBuilder.append("${a + b}\n")
        }
    } while (true)

    print(stringBuilder)
    bufferedReader.close()
}