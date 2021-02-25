/* BOJ - 5622 다이얼 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader

fun costing(word: Char) = when (word) {
    in 'A'..'C' -> 3
    in 'D'..'F' -> 4
    in 'G'..'I' -> 5
    in 'J'..'L' -> 6
    in 'M'..'O' -> 7
    in 'P'..'S' -> 8
    in 'T'..'V' -> 9
    in 'W'..'Z' -> 10
    else -> 0
}

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    bufferedReader.readLine()?.let { words ->
        var answer = 0
        words.forEach { word -> answer += costing(word) }
        println(answer)
    }
}