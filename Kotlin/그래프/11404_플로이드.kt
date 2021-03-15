/* BOJ - 11404 플로이드 */

package boj

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.math.min

const val INF = 100_000_000
const val IMP = 0

fun input() = run {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val city = reader.readLine().toInt()
    val bus = reader.readLine().toInt()
    val adj = Array(city + 1) { IntArray(city + 1) { INF } }

    repeat(bus) {
        StringTokenizer(reader.readLine()).let { token ->
            val from = token.nextToken().toInt()
            val to = token.nextToken().toInt()
            val cost = token.nextToken().toInt()

            if (cost < adj[from][to]) {
                adj[from][to] = cost
            }
        }
    }
    adj
}

fun floydWarshall(costs: Array<IntArray>) = run {
    val n = costs.lastIndex
    for (k in 1..n) {
        for (i in 1..n) {
            if (k == i) continue
            for (j in 1..n) {
                if (i == j) continue
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j])
            }
        }
    }
    costs
}

fun main() {
    val writer = BufferedWriter(OutputStreamWriter(System.out))
    val adj = input()
    val costs = floydWarshall(adj)

    for (from in 1..costs.lastIndex) {
        for (to in 1..costs.lastIndex) {
            if (from == to || costs[from][to] == INF) {
                writer.write("$IMP ")
            } else {
                writer.write("${costs[from][to]} ")
            }
        }
        writer.newLine()
    }
    writer.close()
}