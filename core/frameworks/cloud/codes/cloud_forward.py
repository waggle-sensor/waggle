from pika_connections import Send, CreateQueue, Consume, Connect
import time
con = Connect()
numberOfForwards = 0

def callback(ch, method, properties, body):
    global numberOfForwards
    try:
        Send(con, "cloud_entrance", body)
        numberOfForwards = numberOfForwards + 1
        if numberOfForwards % 10 == 0:
            print time.asctime(), numberOfForwards
        #ch.basic_ack(delivery_tag = method.delivery_tag)
    except:
        print time.asctime(), "Something has gone horribly wrong, I am quitting! - ",  numberOfForwards
        exit()
        #f = open('bad_messages.txt', 'a')
        #f.write(repr(body))
        #f.write('\n')
        #f.close()
        #ch.basic_ack(delivery_tag = method.delivery_tag)


def run():
    CreateQueue(con, "weather")
    CreateQueue(con, "cloud_entrance")
    Consume(callback, 'weather')
if __name__ == "__main__":
    print "Starting forwarder - ", time.asctime()
    run()
