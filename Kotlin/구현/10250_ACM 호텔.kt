/* BOJ - 10250 ACM 호텔 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun checkIn(totalFloorLength: Int, roomLengthOnTheFloor: Int, guest: Int): String {
    val floor: Int
    val room: Int

    if (guest % totalFloorLength == 0) {
        floor = totalFloorLength
        room = guest / totalFloorLength
    } else {
        floor = (guest % totalFloorLength)
        room = guest / totalFloorLength + 1
    }

    return "$floor${room.let { if (it < 10) "0$it" else "$it" }}"
}

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val stringBuilder = StringBuilder()

    repeat(bufferedReader.readLine().toInt()) {
        StringTokenizer(bufferedReader.readLine()).let { Token ->
            val totalFloorLength = Token.nextToken().toInt()
            val roomLengthOnTheFloor = Token.nextToken().toInt()
            val guest = Token.nextToken().toInt()

            stringBuilder.appendLine(checkIn(totalFloorLength, roomLengthOnTheFloor, guest))
        }
    }

    println(stringBuilder)
    bufferedReader.close()
}