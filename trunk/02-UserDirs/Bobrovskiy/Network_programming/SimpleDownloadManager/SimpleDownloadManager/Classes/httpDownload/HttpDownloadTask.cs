﻿using System;
using System.IO;
using System.Net;
using SimpleDownloadManager.Interfaces;

namespace SimpleDownloadManager.Classes.httpDownload
{
    public class HttpDownloadTask : IDownloadTask, IDownload
    {
        private DownloadItem downloadItem = new DownloadItem();
        private BackgroundFileLoader backgroundWorker = null;

        public event Action<DownloadItem> ReportProgress = null;

        public HttpDownloadTask(DownloadItem downloadItem)
        {
            this.downloadItem = downloadItem;
            backgroundWorker = new BackgroundFileLoader(Download);
            backgroundWorker.ProgressChanged += new System.ComponentModel.ProgressChangedEventHandler(backgroundWorker_ProgressChanged);
        }

        void backgroundWorker_ProgressChanged(object sender, System.ComponentModel.ProgressChangedEventArgs e)
        {
            downloadItem.Persentage = e.ProgressPercentage;
            downloadItem.State = (TaskState)e.UserState;
        }

        public DownloadItem CurrentDownloadItem
        {
            get
            {
                return downloadItem;
            }
            set
            {
                downloadItem = value;
            }
        }

        public void Start()
        {
            backgroundWorker.RunWorkerAsync();
        }

        public void Pause()
        {
            backgroundWorker.CancelAsync();
        }

        public void Stop()
        {
            backgroundWorker.CancelAsync();
        }

        public void Download()
        {
            WebRequest request = WebRequest.Create(downloadItem.SourceName);
            request.Credentials = CredentialCache.DefaultCredentials;

            HttpWebResponse response = (HttpWebResponse)request.GetResponse();

            Stream stream = response.GetResponseStream();

            Int64 fileSize = response.ContentLength;
            const int size = 65535;//4096;
            byte[] bytes = new byte[size];
            int numBytes = 0;

            using (FileStream fileStream = new FileStream(downloadItem.DestinationName, FileMode.Create, FileAccess.Write))
            {
                while ((numBytes = stream.Read(bytes, 0, size)) > 0)
                {
                    ReportProgress.Invoke(downloadItem);
                    if (fileStream.Length > 0)
                    {
                        downloadItem.Persentage = (int)((float)fileStream.Length/(float)fileSize*100);
                    }

                    downloadItem.State = TaskState.Processing;

                    fileStream.Write(bytes, 0, numBytes);
                }
            }

            downloadItem.Persentage = 100;
            downloadItem.State = TaskState.Completed;
            ReportProgress.Invoke(downloadItem);


            //const int startPoint = 0;
            //Stream strResponse = null;
            //Stream strLocal = null;

            //HttpWebRequest webRequest = null;
            //HttpWebResponse webResponse = null;

            //try
            //{
            //    // Put the object argument into an int variable
            //    int startPointInt = Convert.ToInt32(startPoint);
            //    // Create a request to the file we are downloading
            //    webRequest = (HttpWebRequest)WebRequest.Create(downloadItem.SourceName);
            //    // Set the starting point of the request
            //    webRequest.AddRange(startPointInt);

            //    // Set default authentication for retrieving the file
            //    webRequest.Credentials = CredentialCache.DefaultCredentials;
            //    // Retrieve the response from the server
            //    webResponse = (HttpWebResponse)webRequest.GetResponse();
            //    // Ask the server for the file size and store it
            //    Int64 fileSize = webResponse.ContentLength;

            //    // Open the URL for download 
            //    strResponse = webResponse.GetResponseStream();

            //    // Create a new file stream where we will be saving the data (local drive)
            //    if (startPointInt == 0)
            //    {
            //        strLocal = new FileStream(downloadItem.DestinationName, FileMode.Create, FileAccess.Write, FileShare.None);
            //    }
            //    else
            //    {
            //        strLocal = new FileStream(downloadItem.DestinationName, FileMode.Append, FileAccess.Write, FileShare.None);
            //    }

            //    // It will store the current number of bytes we retrieved from the server
            //    int bytesSize = 0;
            //    // A buffer for storing and writing the data retrieved from the server
            //    byte[] downBuffer = new byte[2048];
            //    int i = 0;
            //    // Loop through the buffer until the buffer is empty
            //    while ((bytesSize = strResponse.Read(downBuffer, 0, downBuffer.Length)) > 0)
            //    {
            //        // Write the data from the buffer to the local hard drive
            //        ReportProgress.Invoke(downloadItem);
            //        downloadItem.Persentage++;
            //        downloadItem.State = TaskState.Processing;
            //        strLocal.Write(downBuffer, 0, bytesSize);
            //        // Invoke the method that updates the form's label and progress bar
            //    }
            //}
            //finally
            //{
            //    // When the above code has ended, close the streams
            //    strResponse.Close();
            //    strLocal.Close();

            //    downloadItem.Persentage = 100;
            //    downloadItem.State = TaskState.Completed;
            //    ReportProgress.Invoke(downloadItem);
            //}

        }

    }
}
