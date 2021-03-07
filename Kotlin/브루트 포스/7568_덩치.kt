/* BOJ - 7568 덩치 */

package boj

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

data class Physique(val weight: Int, val height: Int)

fun comparePhysique(people1: Physique, people2: Physique) =
        if (people1.weight < people2.weight && people1.height < people2.height) 1 else 0

fun rankByPhysique(peoples: MutableList<Physique>) = run {
    val rank: Array<Int> = Array(peoples.size) { 1 }
    repeat(peoples.size) { current ->
        repeat(peoples.size) { next ->
            if (current != next) {
                rank[current] += comparePhysique(peoples[current], peoples[next])
            }
        }
    }
    rank
}

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val writer = BufferedWriter(OutputStreamWriter(System.out))

    val n = reader.readLine().toInt()
    val peoples = mutableListOf<Physique>()
    repeat(n) {
        StringTokenizer(reader.readLine()).also { token ->
            val weight = token.nextToken().toInt()
            val height = token.nextToken().toInt()
            peoples.add(Physique(weight, height))
        }
    }
    rankByPhysique(peoples).forEach { writer.write("$it ") }
    writer.close()
}