/* BOJ - 2490 윷놀이 */

package boj

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

const val GAME_COUNT = 3
enum class GameResult(val result: Char) {
    MO('E'), DO('A'), GAE('B'), GEOL('C'), YUT('D')
}

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val writer = BufferedWriter(OutputStreamWriter(System.out))

    repeat(GAME_COUNT) {
        val result = when (reader.readLine().count { yut -> yut == '0' }) {
            GameResult.MO.ordinal -> GameResult.MO.result
            GameResult.DO.ordinal -> GameResult.DO.result
            GameResult.GAE.ordinal -> GameResult.GAE.result
            GameResult.GEOL.ordinal -> GameResult.GEOL.result
            GameResult.YUT.ordinal -> GameResult.YUT.result
            else -> null
        }
        writer.write("$result\n")
    }
    writer.close()
}