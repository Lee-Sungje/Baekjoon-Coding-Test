/* BOJ - 4673 셀프 넘버 */

package boj

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

const val NUMBER_MAX_SIZE = 10001
val selfNumbers: Array<Boolean> = Array(NUMBER_MAX_SIZE) { false }

fun isRange(generator: Int) =
        generator <= selfNumbers.lastIndex && !selfNumbers[generator]

fun calculateSelfNumber(generator: Int) {
    if (isRange(generator)) {
        selfNumbers[generator] = true
        calculateSelfNumber(run {
            var nextGenerator = generator
            for (charNumber in generator.toString()) {
                nextGenerator += charNumber - '0'
            }
            nextGenerator
        })
    }
}

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val bufferedWriter = BufferedWriter(OutputStreamWriter(System.out))

    for (number in 1..selfNumbers.lastIndex) {
        if (!selfNumbers[number]) {
            bufferedWriter.write("$number\n")
            calculateSelfNumber(number)
        }
    }

    bufferedReader.close()
    bufferedWriter.close()
}