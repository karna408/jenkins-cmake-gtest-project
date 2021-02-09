pipeline{
    agent any
 
    /*-------- CODE CLONE ------------ */
    stages{
        /*--------------------------- Build Stage ----------------------- */
        stage('Build'){
            steps{
                sh '''
                  cd $WORKSPACE
                  sh build.sh
                  '''
             }
        }
        /*    ----------------- Test Stage ------------------- */
        stage('Test'){
            steps{
                 sh '''
                    cd $WORKSPACE/test
                    
                    mkdir build
                    cd build
                    cmake .. -DCMAKE_PREFIX_PATH=../install
                    make
                    ./app-sample-addition-test
                 '''
              }
       }

     }
     post {
        always {
            archiveArtifacts artifacts: 'test/build/app-sample-addition-test', fingerprint: true
            
        }
    }
  }

