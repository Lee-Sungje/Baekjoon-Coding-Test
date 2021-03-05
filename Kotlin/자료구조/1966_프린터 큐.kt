/* BOJ - 1966 프린터 큐 */

package boj

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

data class Document(val order: Int, val priority: Int)

fun findPrintOrder(printerQueue: Queue<Document>, target: Int): Int {
    var order = 1
    while (!printerQueue.isEmpty()) {
        val front = printerQueue.element()
        if (front.priority == printerQueue.maxOf { it.priority }) {
            if (front.order == target) {
                break
            } else {
                printerQueue.remove()
                order += 1
            }
        } else {
            printerQueue.add(front)
            printerQueue.remove()
        }
    }
    return order
}

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val writer = BufferedWriter(OutputStreamWriter(System.out))

    val testcase = reader.readLine().toInt()
    repeat(testcase) {
        with(StringTokenizer(reader.readLine())) {
            val size = this.nextToken().toInt()
            val target = this.nextToken().toInt()
            val printerQueue: Queue<Document> = LinkedList<Document>()

            StringTokenizer(reader.readLine()).apply {
                repeat(size) { order ->
                    val priority = this.nextToken().toInt()
                    printerQueue.add(Document(order, priority))
                }
            }
            val answer = findPrintOrder(printerQueue, target)
            writer.write("$answer\n")
        }

    }
    writer.close()
}