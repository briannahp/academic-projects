using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
//using System.IO;


public class ShareButton : MonoBehaviour
{
	public Button shareButton;
	private bool isFocus = false; 
	private bool isProcessing = false; 

	void Start()
	{
		shareButton.onClick.AddListener(ShareText);
	}

	void OnApplicationFocus(bool focus)
	{
		isFocus = focus;
	}

	private void ShareText()
	{

#if UNITY_ANDROID
		if(!isProcessing)
		{
			StartCoroutine(ShareTextInAndroid());
		}
#else
		Debug.Log("No sharing set up for this platform");
#endif		
	}

#if UNITY_ANDROID
	public IEnumerator ShareTextInAndroid()
	{
		var shareSubject = "new android game!\n";
		var shareMessage = "Check out this new game on Play store! \n\n" + "app store link\n";

		isProcessing=true;

		if(!Application.isEditor)
		{
			//create intent for action send 
			AndroidJavaClass intentClass = new AndroidJavaClass("android.content.Intent");
			AndroidJavaObject intentObject = new AndroidJavaObject("android.content.Intent");

			intentObject.Call<AndroidJavaObject>
			("setAction", intentClass.GetStatic<string>("ACTION_SEND"));

			//put text and subject extra
			intentObject.Call<AndroidJavaObject>("setType", "text/plain");
			intentObject.Call<AndroidJavaObject>
			("putExtra", intentClass.GetStatic<string>("EXTRA_SUBJECT"), shareSubject);
				intentObject.Call<AndroidJavaObject>
			("putExtra", intentClass.GetStatic<string>("EXTRA_TEXT"), shareMessage);

			//call createChooser method of activity class
			AndroidJavaClass unity = new AndroidJavaClass("com.unity3d.player.UnityPlayer");
			AndroidJavaObject currentActivity = unity.GetStatic<AndroidJavaObject>("currentActivity");
			AndroidJavaObject chooser = intentClass.CallStatic<AndroidJavaObject>
			("createChooser", intentObject, "Share");
			currentActivity.Call("startActivity", chooser);
		}

		yield return new WaitUntil(() => isFocus);
		isProcessing=false;
	}
#endif

}
/* 
{
    public void ClickShare()
    {
		//take screenshot
        StartCoroutine(TakeSSAndShare());
    
	//load local image
	//StartCoroutine(LoadImageAndShare());
	}

    private IEnumerator TakeSSAndShare()
{
	yield return new WaitForEndOfFrame();

	Texture2D ss = new Texture2D( Screen.width, Screen.height, TextureFormat.RGB24, false );
	ss.ReadPixels( new Rect( 0, 0, Screen.width, Screen.height ), 0, 0 );
	ss.Apply();

	string filePath = Path.Combine( Application.temporaryCachePath, "shared img.png" );
	File.WriteAllBytes( filePath, ss.EncodeToPNG() );
	
	// To avoid memory leaks
	Destroy( ss );

	new NativeShare().AddFile( filePath ).Share();
}
*/

/* 
Private IEnumerator LoadImageAndShare()
{
Texture2D image = Resources.Load("image", typeof(Texture2D)) as Texture2D;
yield return null;

string filePath = Path.Combine(Application.temporaryCachePath, "shared img.png");
File.WriteAllBytes(filePath, image.EncodeToPNG());

new NativeShare().AddFile( filePath ).Share();
}
*/

//}

