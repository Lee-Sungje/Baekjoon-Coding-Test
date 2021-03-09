/* BOJ - 1475 방 번호 */

package boj

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

const val DECIMAL_NUMBER = 10

fun minNumberSet(numbers: Array<Int>) = run {
    val reversibleNumber = numbers[6] + numbers[9]
    numbers[6] = reversibleNumber / 2 + reversibleNumber % 2
    numbers[9] = reversibleNumber / 2 + reversibleNumber % 2
    numbers.maxOf { it }
}

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val writer = BufferedWriter(OutputStreamWriter(System.out))
    val numbers: Array<Int> = Array<Int>(DECIMAL_NUMBER) { 0 }

    reader.readLine().apply {
        repeat(this.length) { index -> numbers[this[index] - '0'] += 1 }
    }
    writer.write("${minNumberSet(numbers)}")
    writer.close()
}