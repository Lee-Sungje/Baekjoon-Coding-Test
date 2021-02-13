/* BOJ - 10818 최소, 최대 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val length = bufferedReader.readLine().toInt()
    val stringTokenizer = StringTokenizer(bufferedReader.readLine())

    val numbers = mutableListOf<Int>()
    repeat(length) {
        numbers.add(stringTokenizer.nextToken().toInt())
    }
    val min = numbers.minOf { it }
    val max = numbers.maxOf { it }

    println("$min $max")
    bufferedReader.close()
}