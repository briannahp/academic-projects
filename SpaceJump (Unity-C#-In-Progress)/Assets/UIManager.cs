using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class UIManager : MonoBehaviour
{
    public GameObject SliderPanel;
  //  public Slider slider;
    public Image image;

    public void PlayGame()
    {
       // SceneManager.LoadScene("Level1");
        SliderPanel.SetActive(true);
        StartCoroutine(LoadSceneAsync());
    }

    IEnumerator LoadSceneAsync()
    {
        AsyncOperation operation = SceneManager.LoadSceneAsync("level1");
        while(!operation.isDone)
        {
            float progress = Mathf.Clamp01(operation.progress);
            //slider.value = progress;
            image.fillAmount = progress;
            //update our progress bar to show operation progress
            yield return null;
        }
    }

    
}
