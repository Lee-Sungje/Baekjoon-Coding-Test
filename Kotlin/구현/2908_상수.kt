/* BOJ - 2908 상수 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    StringTokenizer(bufferedReader.readLine()).let {
        val a = it.nextToken().reversed().toInt()
        val b = it.nextToken().reversed().toInt()
        println(if (a < b) b else a)
    }

    bufferedReader.close()
}