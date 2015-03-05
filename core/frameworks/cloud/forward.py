from pika_connections import Send, CreateQueue, Consume, Connect

con = Connect()

def callback(ch, method, properties, body):
    try:
        Send(con, "cloud_entrance", body)
        ch.basic_ack(delivery_tag = method.delivery_tag)
    except:
        print "failed to send"
        f = open('bad_messages.txt', 'a')
        f.write(repr(body))
        f.write('\n')
        f.close()
        ch.basic_ack(delivery_tag = method.delivery_tag)
        

def run():
    CreateQueue(con, "weather")
    CreateQueue(con, "cloud_entrance")
    
    
    Consume(callback, 'weather')

if __name__ == "__main__":
    run()
