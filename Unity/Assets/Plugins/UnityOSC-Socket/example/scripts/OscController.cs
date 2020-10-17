using UnityEngine;
using System.Collections;
using UnityOSC_Socket;
using System.Threading;

public class OscController : MonoBehaviour {

    private OscSocket osc;

    public string host;
    public    int RemotePort;
    public    int ListenPort;

    public string adress;
    public int value_0;
    public long value_1;
    public float value_2;
    public string value_3;
    public byte[] value_4;
    public string value_4_str;

    // Use this for initialization
    void Start () {
        osc = new OscSocket();

        osc.Setup(host, RemotePort, ListenPort);

        //Event handler
        osc.OnMassage += (soket,msg) => {
            Debug.Log(soket.Address);
            Debug.Log(msg.adress);
            Debug.Log(msg.data.Count);
            Debug.Log((int)msg.data[0]);
            Debug.Log((long)msg.data[1]);
            Debug.Log((float)msg.data[2]);
            Debug.Log((string)msg.data[3]);
            Debug.Log((byte[])msg.data[4]);

            adress = msg.adress;
            value_0 = (int)msg.data[0];
            value_1 = (long)msg.data[1];
            value_2 = (float)msg.data[2];
            value_3 = (string)msg.data[3];
            value_4 = (byte[])msg.data[4];

            value_4_str = System.Text.Encoding.ASCII.GetString(value_4);
        };
    }
	
	// Update is called once per frame
	void Update () 
    {
	    if(Input.GetKeyDown(KeyCode.Space)){
            var message = new OscMessage();
            message.setAdress("/unity");
            message.addIntArg(1);
            message.addInt64Arg(Time.frameCount);
            message.addFloatArg(9.9f);
            message.addStringArg("hogehoge");

            byte[] data = System.Text.Encoding.ASCII.GetBytes("test");
            message.addBlobArg(data);

            osc.send(message);
        }
	}

    void OnApplicationQuit()
    {
        osc.close();
    }
}
