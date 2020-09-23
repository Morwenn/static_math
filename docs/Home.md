Welcome to the `static_math` wiki!

You probably already read all the promotional stuff in the project's README, so I we won't be repeating that here. The library is rather simple and small so the documentation will be a bit boring and straightforward while probably really close to a regular Doxygen documentation. To be honest, if you want to know more about one of the library features, you might as well directly read the source code, which should be readable enough. There is *one* notable exception to this rule: the return type of some functions is fully specified in this documentation while it may be `decltype(auto)` in the source code. This is because some of these functions support [[integral constants]] and their return type may be a bit more tricky; the documented return type is the one you can expect when you are not using integral constants.

Also, note that this documentation documents what functions or classes you should expect to find when including a header, even if you are bound to include more because of headers interdependencies. This problem would be solved by modules, but they are still not in the standard.

If you ever feel that this wiki is incomplete, that it needs more examples or more detailed explanation about stuff, you are welcome to report it and/or contribute.

Hope this will be useful!