# Contributing to the C Track

Thank you for interest in contributing to the Exercism C language track!
All contributions are welcome, be it a new exercise, a change to the tooling or documentation, a raised issue or even just a comment on an existing issue or PR.
This file provides information to help you get started.

Firstly, have a read of the Exercism [docs repository](https://github.com/exercism/docs), specifically the information on [contributing to a language track](https://github.com/exercism/docs/blob/master/contributing-to-language-tracks/README.md), as these documents cover a lot of the basic information.

Subsequently note that there are a few things specific to this repository that are explained below.

We encourage contributions that provide fixes and improvements to existing exercises.
Please note that this track's exercises must conform to the standards determined in the [problem-specifications](https://github.com/exercism/problem-specifications) repository.
Changes to the tests or documentation of a common exercise will often warrant a pull request in that repository before it can be incorporated into this track's exercises.
If you're unsure, then go ahead and open a GitHub [issue](https://github.com/exercism/c/blob/master/docs/CONTRIBUTING.md#issues), and we'll discuss the change.

## Code of Conduct

Help us keep Exercism welcoming.
Please read and abide by the [Code of Conduct](https://exercism.io/code-of-conduct).

## Git Workflow

1. Fork and clone.
2. Add this repository as a new remote to your clone: `git remote add upstream https://github.com/exercism/c.git`
3. Create a new branch: `git checkout -b name-of-branch`
4. Commit and push as usual on your new branch
5. When you're ready to submit a pull request, rebase your branch onto the upstream master so that you can resolve any conflicts: `git fetch upstream && git rebase upstream/master` You may need to push up to your branch using `--force` after resolving conflicts.
6. When you've got everything ready, push up to your branch and create the pull request as outlined below.

## Issues

We keep track of bugs, enhancements and support requests in the repository using GitHub [issues](https://github.com/exercism/c/issues).

For higher-level discussions about the project as a whole, check out the issues in the [discussions](https://github.com/exercism/discussions/issues) repository.

### Good First Patch

We're trying to label issues with "good first patch" if we think that these can be solved without too much context about Exercism's codebase or functionality. To find them, you can do a [search](https://github.com/exercism/c/good-first-patch).

## Pull Requests

It would be awesome if you follow these [simple guidelines](https://github.com/exercism/docs/blob/master/contributing/pull-request-guidelines.md) while creating your PR, but it isn't required.

Pull requests should be focused on a single, issue or change.
We welcome changes to code style and wording but please open a separate PR for these changes if possible.
Please open an issue before creating a PR that makes significant (breaking) changes to an existing exercise or makes changes across many exercises. It is best to discuss these changes before doing the work.

If your change is to an exercise you can run the CI scripts before submitting the pull request, or they will be automatically run after, as described in [Continuous Integration & Tests](https://github.com/exercism/c/blob/master/docs/CONTRIBUTING.md#continuous-integration--tests)

When submitting a pull request, sometimes we will ask you to make changes before we accept the patch.

Please do not close the first pull request and open a second one with these changes.
If you push more commits to a branch that you've opened a pull request for, it automatically updates the pull request.

If you want to create a PR with changes that aren't quite ready to be merged to master yet (maybe you would like to discuss some particular item, for example), create the PR as normal but add `[WIP]` to the title so that maintainers know that it isn't quite ready to be merged just yet.

As with adding more commits, you do not need to close your pull request and open a new one if you change the history (rebase, squash, amend), and use git push --force to update the branch on your fork.
The pull request points to that branch, not to specific commits.

## Coding Style

The code style expected for code change contributions is explained in the [style guide](https://github.com/exercism/c/blob/master/docs/C_STYLE_GUIDE.md).

The exercise code is checked during [CI](https://github.com/exercism/c/blob/master/docs/CONTRIBUTING.md#continuous-integration--tests) for conformance to the spacing and indentation style rules.
The check uses the GNU `indent` CLI tool.
When adding or making a change to an exercise, you can check that your change conforms to these rules by running the tool locally before committing.

On Linux `indent` should be available for install via your distribution's package manager.
On a Mac you can install the package `gnu-indent` using [Homebrew](https://brew.sh).

Indent can be run on all files by executing `indent.sh`.
To manually run it on a single file, you can execute:

```bash
indent -linux -i3 -nut $(file)
```

If your system does not support the `-linux` option, you can run the long-form command instead:

```bash
indent -nbad -bap -nbc -bbo -hnl -br -brs -c33 -cd33 -ncdb -ce -ci4 -cli0 -d0 -di1 -nfc1 -i3 -nut -ip0 -l80 -lp -npcs -nprs -npsl -sai -saf -saw -ncs -nsc -sob -nfca -cp33 -ss -il1 $(file)
```

## Exercise anatomy

Each exercise should be contained in a directory `c/exercises/<my exercise>` with `<my exercise>` referring to the name of the exercise.
See [implement-an-exercise-from-specification](https://github.com/exercism/docs/blob/master/you-can-help/implement-an-exercise-from-specification.md) for in depth details on implementing an exercise that matches the specification

The structure of en exercise's directory is as follows (note the differing hyphen and underscore usage for directory names and file names respectively):

<pre>
+-- &lt;my-exercise&gt;
    +-- makefile
    +-- README.md
    +-- src
    |   +-- example.c
    |   +-- example.h | <my_exercise>.h
    +-- test
        +-- test_<my_exercise>.c
        +-- vendor
            +-- unity.c
            +-- unity.h
            +-- unity_internals.h
</pre>

* `test` - contains the test file `test_<my exercise>.c` and a `vendor` directory containing the test harness [Unity](http://www.throwtheswitch.org/unity/) from [ThrowTheSwitch](http://www.throwtheswitch.org/#intro-1-section).
  ThrowTheSwitch has a decent guide on [getting started with Unity](http://www.throwtheswitch.org/getting-started-with-unity/) should you desire a tutorial. The version of Unity used is indicated in [versions](https://www.github.com/exercism/c/blob/master/docs/VERSIONS.md). The layout of the test file is described in the [style guide](https://github.com/exercism/c/blob/master/docs/C_STYLE_GUIDE.md#test-file-layout). Tests should be written that satisfy the exercise's related `canonical-data.json` file in the [`problem-specifications`](https://github.com/exercism/problem-specifications) repository
* `src` - contains the example files `example.c` and `example.h`. These are both skipped by the `exercism` CLI when downloading to the client, so it is imperative that you do not reference the names of the files in your code.
  If you need to provide a header file example that is necessary to run your tests it should be named `<my exercise>.h` instead.
  Please also use [`include`](http://faculty.cs.niu.edu/~mcmahon/CS241/c241man/node90.html) guards in your header files.
  The [tests](https://github.com/exercism/c/blob/master/docs/CONTRIBUTING.md#what-are-the-ci-scripts) can be run using the [`bin/run-tests`](https://github.com/exercism/c/blob/master/bin/run-tests) script which will rename the `example.{c|h}` files accordingly.
* `makefile` - is the makefile for the exercise as it would build using proper filenames (i.e. `<exercise>.c` and `<exercise>.h` instead of `example.c` and `example.h` respectively). Makefiles are expected to change very little between exercises so it should be easy to copy one from another exercise and adjust the filenames therein.
* `README.md` - is the readme that relates to the exercise. These can be generated by the [configlet](https://github.com/exercism/configlet#configlet) tool from the exercise's  related `description.md` in the [`problem-specifications`](https://github.com/exercism/problem-specifications) repository, or alternatively a custom one can be written.

**Don't forget** to add the exercise to the track's `config.json`. For this you will need to determine the best place to add the exercise within the order of all other track exercises. You will also need to generate a UUID to add here. For both of these tasks you can use the [configlet](https://github.com/exercism/configlet#configlet) tool; the tool will even lint and format the `config.json` for you after you've made these changes!

FYI - to get the install artifact for the configlet tool, checkout the configlet repository's [releases page](https://github.com/exercism/configlet/releases)

## Continuous Integration & Tests

This repository uses GitHub workflows to run some scripts on each commit to a pull request.
The simplest way to run these scripts on your own contribution is to open a PR on this repository with your changes, set the PR draft, then allow this repository's CI setup to take care of things for you automatically.

### CI environment

GitHub runs the CI on virtual machines it refers to as [hosted runners][hosted-runners].
Workflows can configure some aspects of the runners they would like to be run on.

The workflows in this repository specify only that they each should be run on Ubuntu 18.04.
The later LTS version of Ubuntu (20.04) is specifically not used due to ongoing work by GitHub on the virtual machines.
This work means that specifying `latest`, for example, is not guaranteed to result in 20.04 machine, but could result in an 18.04 one.
As some of the tools (namely `indent`) perform differently on different these different OS versions, the maintainers of this repo have taken the decision to stay with 18.04 until GitHub have completed their work (see [actions/virtual-environments#1816][1816] for information on progress).

### Run CI on Your Own Fork

If you would like, it is also possible to run the CI on your own fork, simply clone this repository as normal on GitHub.
The YAML files located in [`./.github/workflows/`][workflows] should work just the same.
If you would like the [`/format`][format-workflow] automated action to work correctly, you will need to add a deploy key to your cloned repository.

### The Workflows

* `checks.yml` runs `shellcheck` on the tool scripts and subsequently runs the following of those tools:
  * `./bin/verify-indent`
  * `./bin/check-unitybegin`
  * `./bin/verify-unity-version`
* `configlet.yml` fetches the latest version of configlet from which it then runs the `lint` command on the track
* `format-code.yml` checks for the string `/format` within any comment on a PR, if it finds it then `indent` is run on the exercises and any resulting changes are committed. A deploy key is required for the commit to be able to re-trigger CI. The deploy key is administered by Exercism directly.
* `build.yml` runs the `./bin/run-tests` tool on all exercises

### The Tools

You can see from the [workflows][] that GitHub is instructed to run tools from the [`./bin`](https://github.com/exercism/c/tree/master/bin) directory.
The work the tools in this directory perform is described as follows:

* `check-unitybegin` ensures that every test file correctly adds the `UnityBegin("{test-file-name}")` line at the start of its `main()` function.
* `fetch-configlet` fetches the `configlet` tool from its [repository](https://github.com/exercism/configlet).
* `verify-indent` runs the `indent` tool and verifies that it did not result in any file changes.
* `verify-unity-version` checks the version of the Unity test framework used by every exercise. The version this file should check for is specified in [`./docs/VERSIONS.md`][versions]
* `run-tests` loops through each exercise, prepares the exercise for building and then builds it using `make`, runs the unit tests and then checks it for memory leaks with AddressSanitizer.

### Run Tools Locally

You can also run individual tools on your own machine before committing.
Firstly make sure you have the necessary applications installed (such as `indent`, [`git`](https://git-scm.com/), [`sed`](https://www.gnu.org/software/sed/manual/sed.html), [`make`](https://www.gnu.org/software/make/) and a C compiler), and then run the required tool from the repository root. For example:

```bash
~/git/c$ ./bin/run-tests
```

If you'd like to run only some of the tests to check your work, you can specify them as arguments to the run-tests script.

```bash
~/git/c$ ./bin/run-tests acronym all-your-base allergies
```

[hosted-runners]: https://docs.github.com/en/actions/using-github-hosted-runners/about-github-hosted-runners
[1816]: https://github.com/actions/virtual-environments/issues/1816
[workflows]: https://github.com/exercism/c/blob/master/.github/workflows/
[format-workflow]: https://github.com/exercism/c/blob/master/.github/workflows/format-code.yml
[versions]: https://github.com/exercism/c/blob/master/docs/VERSIONS.md
