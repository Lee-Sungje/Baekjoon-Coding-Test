/* BOJ - 10817 세 수 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val stringTokenizer = StringTokenizer(bufferedReader.readLine())

    val answer = run {
        val numbers = mutableListOf<Int>()
        for (token in stringTokenizer) {
            numbers.add(token.toString().toInt())
        }
        numbers.sort()
        numbers[1]
    }

    println(answer)
    bufferedReader.close()
}