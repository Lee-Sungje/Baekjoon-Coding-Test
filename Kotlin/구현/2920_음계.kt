/* BOJ - 2920 음계 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

const val ASCENDING = 0
const val DESCENDING = 1
const val MIXED = 2
const val NOTE_SIZE = 8

fun checkOrder(notes: Array<Int>): Int {
    var order = if (notes.first() < notes.last()) ASCENDING else DESCENDING

    for (index in 0 until notes.lastIndex) {
        when (order) {
            ASCENDING -> if (notes[index] > notes[index + 1]) order = MIXED
            DESCENDING -> if (notes[index] < notes[index + 1]) order = MIXED
            MIXED -> break
        }
    }

    return order
}

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))

    StringTokenizer(bufferedReader.readLine()).let { Token ->
        val notes: Array<Int> = Array(NOTE_SIZE) { Token.nextToken().toInt() }
        when(checkOrder(notes)) {
            ASCENDING -> println("ascending")
            DESCENDING -> println("descending")
            MIXED -> println("mixed")
        }
    }

    bufferedReader.close()
}