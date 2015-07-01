from cloud_pika_connections import Send, CreateQueue, Consume, Connect
import time
con = Connect()
numberOfForwards = 0

def weather_attender(ch, method, properties, body):
    global numberOfForwards
    try:
        Send(con, "cloud_entrance", body)
        numberOfForwards = numberOfForwards + 1
        if numberOfForwards % 10 == 0:
            print time.asctime(), numberOfForwards
            pass
        ch.basic_ack(delivery_tag = method.delivery_tag)

    except:
        print time.asctime(), "Something is wrong, moving on... ",  numberOfForwards
        ch.basic_ack(delivery_tag = method.delivery_tag)


def run():
    print "Starting forwarder - ", time.asctime()
    CreateQueue(con, "weather")
    print "Connected to Weather."
    CreateQueue(con, "cloud_entrance")
    print "Connected to cloud_entrance."
    Consume(weather_attender, 'weather')


if __name__ == "__main__":
    print "Starting forwarder - ", time.asctime()
    run()
