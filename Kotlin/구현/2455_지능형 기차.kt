/* BOJ - 2455 지능형 기차 */

package boj

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

const val STATION_LENGTH = 4

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val writer = BufferedWriter(OutputStreamWriter(System.out))

    var total = 0
    var max = 0
    repeat(STATION_LENGTH) {
        StringTokenizer(reader.readLine()).let { token ->
            val getOff = token.nextToken().toInt()
            val getOn = token.nextToken().toInt()
            total += getOn - getOff
            max = if (max < total) total else max
        }
    }
    writer.write("$max")
    writer.close()
}