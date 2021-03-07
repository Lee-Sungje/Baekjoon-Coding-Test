/* BOJ - 2475 검증수 */

package boj

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

const val SERIAL_NUMBER_LENGTH = 5

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val writer = BufferedWriter(OutputStreamWriter(System.out))

    val verificationNumber = StringTokenizer(reader.readLine()).let { serialNumbers ->
        var serialNumberTotal = 0
        repeat(SERIAL_NUMBER_LENGTH) {
            val fragment = serialNumbers.nextToken().toInt()
            serialNumberTotal += fragment * fragment
        }
        serialNumberTotal % 10
    }
    writer.write("$verificationNumber\n")
    writer.close()
}