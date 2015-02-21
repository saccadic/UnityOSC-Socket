#UnityOSC-Socket
UnityOSC-SocketはOSCプロトコルによる双方向通信をシンプルに提供するライブラリです。    
Windows & Mac ともに利用可能です。Unity3D Free版でも動作します。

##ToDo
+ Unityからサイズの大きいBlobデータを送信すると正しくパケットが作成されない。
+ エラー処理の追加
+ UDP以外のプロトコルでも利用してみる

##参考
+ keijiro Unity-osc:<https://github.com/keijiro/unity-osc>
+ jorgegarcia UnityOSC:<https://github.com/jorgegarcia/UnityOSC>
+ ofxOSC:<https://github.com/openframeworks/openFrameworks/tree/master/addons/ofxOsc>

##使い方
###サンプル：OscController.cs 

        using UnityEngine;
        using System.Collections;
        using UnityOSC;

        public class OscController : MonoBehaviour {

            private OscSocket osc;

            public string host;　　　　//相手のIPアドレス
            public    int RemotePort;　//相手のポート番号
            public    int ListenPort;　//自分のポート番号

            // Use this for initialization
        	void Start () {
                osc = new OscSocket();

                osc.Setup(host, RemotePort, ListenPort); //初期設定

                osc.OnMassage += (soket,msg) => { //受信イベント
                    Debug.Log(soket.Address);
                    Debug.Log((int)msg.data[0]);
                    Debug.Log((long)msg.data[1]);
                    Debug.Log((float)msg.data[2]);
                    Debug.Log((string)msg.data[3]);
                    Debug.Log((byte[])msg.data[4]);
                };
            }

        	// Update is called once per frame
        	void Update ()
            {
        	    if(Input.GetKeyDown(KeyCode.Space)){
                    var message = new OscMessage();　//送信メッセージ
                    message.setAdress("/from/unity/");　//OSCアドレス
                    message.addIntArg(1);　//Int32型
                    message.addInt64Arg(1);//Long型
                    message.addFloatArg(9.9f);//Float型
                    message.addStringArg("hogehoge");//String型

                    byte[] data = System.Text.Encoding.ASCII.GetBytes("test");
                    message.addBlobArg(data);//Byte[]型

                    osc.send(message);//送信
                }
        	}

            void OnApplicationQuit()
            {
                osc.close();//終了処理
            }
        }
